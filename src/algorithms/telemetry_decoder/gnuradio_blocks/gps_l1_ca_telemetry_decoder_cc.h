/*!
 * \file gps_l1_ca_telemetry_decoder_cc.h
 * \brief Interface of a NAV message demodulator block based on
 * Kay Borre book MATLAB-based GPS receiver
 * \author Javier Arribas, 2011. jarribas(at)cttc.es
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

#ifndef GNSS_SDR_GPS_L1_CA_TELEMETRY_DECODER_CC_H
#define GNSS_SDR_GPS_L1_CA_TELEMETRY_DECODER_CC_H

#include "GPS_L1_CA.h"
#include "gnss_satellite.h"
#include "gnss_synchro.h"
#include "gps_navigation_message.h"
#include <boost/circular_buffer.hpp>
#include <gnuradio/block.h>
#include <fstream>
#include <string>

class gps_l1_ca_telemetry_decoder_cc;

typedef boost::shared_ptr<gps_l1_ca_telemetry_decoder_cc> gps_l1_ca_telemetry_decoder_cc_sptr;

gps_l1_ca_telemetry_decoder_cc_sptr
gps_l1_ca_make_telemetry_decoder_cc(const Gnss_Satellite &satellite, bool dump);

/*!
 * \brief This class implements a block that decodes the NAV data defined in IS-GPS-200E
 *
 */
class gps_l1_ca_telemetry_decoder_cc : public gr::block
{
public:
    ~gps_l1_ca_telemetry_decoder_cc();
    void set_satellite(const Gnss_Satellite &satellite);  //!< Set satellite PRN
    void set_channel(int channel);                        //!< Set receiver's channel

    /*!
     * \brief This is where all signal processing takes place
     */
    int general_work(int noutput_items, gr_vector_int &ninput_items,
        gr_vector_const_void_star &input_items, gr_vector_void_star &output_items);

private:
    friend gps_l1_ca_telemetry_decoder_cc_sptr
    gps_l1_ca_make_telemetry_decoder_cc(const Gnss_Satellite &satellite, bool dump);

    gps_l1_ca_telemetry_decoder_cc(const Gnss_Satellite &satellite, bool dump);

    bool gps_word_parityCheck(uint32_t gpsword);

    bool decode_subframe();
    bool new_decoder();
    int d_crc_error_synchronization_counter;

    int *d_preambles_symbols;
    uint32_t d_stat;
    bool d_flag_frame_sync;

    // symbols
    boost::circular_buffer<Gnss_Synchro> d_symbol_history;
    float d_subframe_symbols[GPS_SUBFRAME_MS]{};  // symbols per subframe
    int d_current_subframe_symbol;

    // bits and frame
    uint32_t d_prev_GPS_frame_4bytes;
    bool d_flag_preamble;
    bool d_flag_new_tow_available;

    // navigation message vars
    Gps_Navigation_Message d_nav;

    bool d_dump;
    Gnss_Satellite d_satellite;
    int d_channel;

    uint64_t d_preamble_time_samples;

    uint32_t d_TOW_at_Preamble_ms;
    uint32_t d_TOW_at_current_symbol_ms;

    bool flag_TOW_set;
    bool flag_PLL_180_deg_phase_locked;

    std::string d_dump_filename;
    std::ofstream d_dump_file;
};

#endif
