/*!
 * \file rtklib_pvt_cc.h
 * \brief Interface of a Position Velocity and Time computation block
 * \author Javier Arribas, 2017. jarribas(at)cttc.es
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2018  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * GNSS-SDR is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GNSS-SDR is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNSS-SDR. If not, see <https://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------
 */

#ifndef GNSS_SDR_RTKLIB_PVT_CC_H
#define GNSS_SDR_RTKLIB_PVT_CC_H

#include "geojson_printer.h"
#include "gps_ephemeris.h"
#include "gpx_printer.h"
#include "kml_printer.h"
#include "nmea_printer.h"
#include "pvt_conf.h"
#include "rinex_printer.h"
#include "rtcm_printer.h"
#include "rtklib_solver.h"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <gnuradio/sync_block.h>
#include <chrono>
#include <cstdint>
#include <fstream>
#include <string>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <utility>


class rtklib_pvt_cc;

typedef boost::shared_ptr<rtklib_pvt_cc> rtklib_pvt_cc_sptr;

rtklib_pvt_cc_sptr rtklib_make_pvt_cc(uint32_t n_channels,
    const Pvt_Conf& conf_,
    const rtk_t& rtk);

/*!
 * \brief This class implements a block that computes the PVT solution using the RTKLIB integrated library
 */
class rtklib_pvt_cc : public gr::sync_block
{
private:
    friend rtklib_pvt_cc_sptr rtklib_make_pvt_cc(uint32_t nchannels,
        const Pvt_Conf& conf_,
        const rtk_t& rtk);

    void msg_handler_telemetry(pmt::pmt_t msg);

    bool d_dump;
    bool d_dump_mat;
    bool b_rinex_output_enabled;
    bool b_rinex_header_written;
    bool b_rinex_header_updated;
    double d_rinex_version;
    int32_t d_rinexobs_rate_ms;
    int32_t d_rinexnav_rate_ms;

    bool b_rtcm_writing_started;
    bool b_rtcm_enabled;
    int32_t d_rtcm_MT1045_rate_ms;  //!< Galileo Broadcast Ephemeris
    int32_t d_rtcm_MT1019_rate_ms;  //!< GPS Broadcast Ephemeris (orbits)
    int32_t d_rtcm_MT1020_rate_ms;  //!< GLONASS Broadcast Ephemeris (orbits)
    int32_t d_rtcm_MT1077_rate_ms;  //!< The type 7 Multiple Signal Message format for the USA’s GPS system, popular
    int32_t d_rtcm_MT1087_rate_ms;  //!< GLONASS MSM7. The type 7 Multiple Signal Message format for the Russian GLONASS system
    int32_t d_rtcm_MT1097_rate_ms;  //!< Galileo MSM7. The type 7 Multiple Signal Message format for Europe’s Galileo system
    int32_t d_rtcm_MSM_rate_ms;

    int32_t d_last_status_print_seg;  //for status printer

    uint32_t d_nchannels;
    std::string d_dump_filename;

    int32_t d_output_rate_ms;
    int32_t d_display_rate_ms;

    std::shared_ptr<Rinex_Printer> rp;
    std::shared_ptr<Kml_Printer> d_kml_dump;
    std::shared_ptr<Gpx_Printer> d_gpx_dump;
    std::shared_ptr<Nmea_Printer> d_nmea_printer;
    std::shared_ptr<GeoJSON_Printer> d_geojson_printer;
    std::shared_ptr<Rtcm_Printer> d_rtcm_printer;
    double d_rx_time;

    bool d_geojson_output_enabled;
    bool d_gpx_output_enabled;
    bool d_kml_output_enabled;
    bool d_nmea_output_file_enabled;

    std::shared_ptr<rtklib_solver> d_pvt_solver;

    std::map<int, Gnss_Synchro> gnss_observables_map;
    bool observables_pairCompare_min(const std::pair<int, Gnss_Synchro>& a, const std::pair<int, Gnss_Synchro>& b);

    uint32_t type_of_rx;

    bool first_fix;
    key_t sysv_msg_key;
    int sysv_msqid;
    typedef struct
    {
        long mtype;  //required by sys v message
        double ttff;
    } ttff_msgbuf;
    bool send_sys_v_ttff_msg(ttff_msgbuf ttff);
    std::chrono::time_point<std::chrono::system_clock> start, end;

    bool save_gnss_synchro_map_xml(const std::string& file_name);  //debug helper function

    bool load_gnss_synchro_map_xml(const std::string& file_name);  //debug helper function

    bool d_xml_storage;
    std::string xml_base_path;

    inline std::time_t to_time_t(boost::posix_time::ptime pt)
    {
        return (pt - boost::posix_time::ptime(boost::gregorian::date(1970, 1, 1))).total_seconds();
    }


public:
    rtklib_pvt_cc(uint32_t nchannels,
        const Pvt_Conf& conf_,
        const rtk_t& rtk);

    /*!
     * \brief Get latest set of ephemeris from PVT block
     *
     */
    std::map<int, Gps_Ephemeris> get_gps_ephemeris_map() const;

    std::map<int, Gps_Almanac> get_gps_almanac_map() const;

    std::map<int, Galileo_Ephemeris> get_galileo_ephemeris_map() const;

    std::map<int, Galileo_Almanac> get_galileo_almanac_map() const;

    /*!
     * \brief Clear all ephemeris information and the almanacs for GPS and Galileo
     *
     */
    void clear_ephemeris();

    /*!
     * \brief Get the latest Position WGS84 [deg], Ground Velocity, Course over Ground, and UTC Time, if available
     */
    bool get_latest_PVT(double* longitude_deg,
        double* latitude_deg,
        double* height_m,
        double* ground_speed_kmh,
        double* course_over_ground_deg,
        time_t* UTC_time);

    ~rtklib_pvt_cc();  //!< Default destructor

    int work(int noutput_items, gr_vector_const_void_star& input_items,
        gr_vector_void_star& output_items);  //!< PVT Signal Processing
};

#endif
