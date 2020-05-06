/*!
 * \file channel_fsm.h
 * \brief Interface of the State Machine for channel
 * \authors Javier Arribas, 2019. javiarribas@gmail.com
 *          Antonio Ramos, 2017. antonio.ramos(at)cttc.es
 *          Luis Esteve,   2011. luis(at)epsilon-formacion.com
 *
 * -------------------------------------------------------------------------
 *
 * Copyright (C) 2010-2019  (see AUTHORS file for a list of contributors)
 *
 * GNSS-SDR is a software defined Global Navigation
 *          Satellite Systems receiver
 *
 * This file is part of GNSS-SDR.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * -------------------------------------------------------------------------
 */

#ifndef GNSS_SDR_CHANNEL_FSM_H
#define GNSS_SDR_CHANNEL_FSM_H

#include "acquisition_interface.h"
#include "concurrent_queue.h"
#include "telemetry_decoder_interface.h"
#include "tracking_interface.h"
#include <pmt/pmt.h>
#include <cstdint>
#include <memory>
#include <mutex>


/*!
 * \brief This class implements a State Machine for channel
 */
class ChannelFsm
{
public:
    ChannelFsm();
    virtual ~ChannelFsm() = default;
    explicit ChannelFsm(std::shared_ptr<AcquisitionInterface> acquisition);

    void set_acquisition(std::shared_ptr<AcquisitionInterface> acquisition);
    void set_tracking(std::shared_ptr<TrackingInterface> tracking);
    void set_telemetry(std::shared_ptr<TelemetryDecoderInterface> telemetry);
    void set_queue(std::shared_ptr<Concurrent_Queue<pmt::pmt_t>> queue);
    void set_channel(uint32_t channel);
    void start_acquisition();
    // FSM EVENTS
    bool Event_start_acquisition();
    bool Event_start_acquisition_fpga();
    virtual bool Event_valid_acquisition();
    bool Event_stop_channel();
    virtual bool Event_failed_acquisition_repeat();
    virtual bool Event_failed_acquisition_no_repeat();
    bool Event_failed_tracking_standby();

private:
    void start_tracking();
    void stop_acquisition();
    void stop_tracking();
    void request_satellite();
    void notify_stop_tracking();

    std::shared_ptr<AcquisitionInterface> acq_;
    std::shared_ptr<TrackingInterface> trk_;
    std::shared_ptr<TelemetryDecoderInterface> nav_;
    std::shared_ptr<Concurrent_Queue<pmt::pmt_t>> queue_;
    uint32_t channel_;
    uint32_t d_state;
    std::mutex mx;
};

#endif  // GNSS_SDR_CHANNEL_FSM_H
