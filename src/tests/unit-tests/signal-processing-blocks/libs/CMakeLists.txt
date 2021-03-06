# Copyright (C) 2012-2020  (see AUTHORS file for a list of contributors)
#
# GNSS-SDR is a software-defined Global Navigation Satellite Systems receiver
#
# This file is part of GNSS-SDR.
#
# SPDX-License-Identifier: GPL-3.0-or-later
#


set(SIGNAL_PROCESSING_TESTING_LIB_SOURCES
    acquisition_dump_reader.cc
    acquisition_msg_rx.cc
    tracking_dump_reader.cc
    tlm_dump_reader.cc
    observables_dump_reader.cc
    tracking_true_obs_reader.cc
    true_observables_reader.cc
)

file(GLOB SIGNAL_PROCESSING_TESTING_LIB_HEADERS "*.h")
list(SORT SIGNAL_PROCESSING_TESTING_LIB_HEADERS)

add_library(signal_processing_testing_lib
    ${SIGNAL_PROCESSING_TESTING_LIB_SOURCES}
    ${SIGNAL_PROCESSING_TESTING_LIB_HEADERS}
)

source_group(Headers FILES ${SIGNAL_PROCESSING_TESTING_LIB_HEADERS})

target_link_libraries(signal_processing_testing_lib
    PUBLIC
        Armadillo::armadillo
        Gflags::gflags
        Gnuradio::runtime
    PRIVATE
        Boost::headers
        Matio::matio
        Glog::glog
)

if(ENABLE_CLANG_TIDY)
    if(CLANG_TIDY_EXE)
        set_target_properties(signal_processing_testing_lib
            PROPERTIES
                CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
        )
    endif()
endif()

set_property(TARGET signal_processing_testing_lib
    APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
