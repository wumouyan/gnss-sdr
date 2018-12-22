# Copyright (C) 2011-2018 (see AUTHORS file for a list of contributors)
#
# This file is part of GNSS-SDR.
#
# GNSS-SDR is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# GNSS-SDR is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with GNSS-SDR. If not, see <https://www.gnu.org/licenses/>.

# - Try to find OpenBLAS library (not headers!)
#
# The following environment variable is optionally searched
# OPENBLAS_HOME: Base directory where all OpenBlas components are found

set(OPEN_BLAS_SEARCH_PATHS
    /lib
    /lib64/
    /usr/lib
    /usr/lib64
    /usr/local/lib
    /usr/local/lib64
    /opt/OpenBLAS/lib
    /opt/local/lib
    /usr/lib/openblas-base
    $ENV{OPENBLAS_HOME}/lib
    ${OPENBLAS_ROOT}/lib
    $ENV{OPENBLAS_ROOT}/lib
    ${OPENBLAS_ROOT}/lib64
    $ENV{OPENBLAS_ROOT}/lib64
)

find_library(OPENBLAS NAMES openblas PATHS ${OPEN_BLAS_SEARCH_PATHS})

if(OPENBLAS)
    set(OPENBLAS_FOUND ON)
    message(STATUS "Found OpenBLAS")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(OPENBLAS DEFAULT_MSG OPENBLAS)
mark_as_advanced(OPENBLAS)
