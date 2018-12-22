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

########################################################################
# Find the library for the USRP Hardware Driver
########################################################################

include(FindPkgConfig)
pkg_check_modules(PC_UHD uhd)

find_path(UHD_INCLUDE_DIRS
    NAMES uhd/config.hpp
    HINTS $ENV{UHD_DIR}/include
          ${PC_UHD_INCLUDEDIR}
    PATHS /usr/local/include
          /usr/include
          ${GNURADIO_INSTALL_PREFIX}/include
          ${UHD_ROOT}/include
          $ENV{UHD_ROOT}/include
)

find_library(UHD_LIBRARIES
    NAMES uhd
    HINTS $ENV{UHD_DIR}/lib
          ${PC_UHD_LIBDIR}
    PATHS /usr/local/lib
          /usr/lib/x86_64-linux-gnu
          /usr/lib/i386-linux-gnu
          /usr/lib/arm-linux-gnueabihf
          /usr/lib/arm-linux-gnueabi
          /usr/lib/aarch64-linux-gnu
          /usr/lib/mipsel-linux-gnu
          /usr/lib/mips-linux-gnu
          /usr/lib/mips64el-linux-gnuabi64
          /usr/lib/powerpc-linux-gnu
          /usr/lib/powerpc64-linux-gnu
          /usr/lib/powerpc64le-linux-gnu
          /usr/lib/powerpc-linux-gnuspe
          /usr/lib/hppa-linux-gnu
          /usr/lib/s390x-linux-gnu
          /usr/lib/i386-gnu
          /usr/lib/hppa-linux-gnu
          /usr/lib/x86_64-kfreebsd-gnu
          /usr/lib/i386-kfreebsd-gnu
          /usr/lib/m68k-linux-gnu
          /usr/lib/sh4-linux-gnu
          /usr/lib/sparc64-linux-gnu
          /usr/lib/x86_64-linux-gnux32
          /usr/lib/alpha-linux-gnu
          /usr/lib64
          /usr/lib
          ${GNURADIO_INSTALL_PREFIX}/lib
          ${UHD_ROOT}/lib
          $ENV{UHD_ROOT}/lib
          ${UHD_ROOT}/lib64
          $ENV{UHD_ROOT}/lib64
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(UHD DEFAULT_MSG UHD_LIBRARIES UHD_INCLUDE_DIRS)
mark_as_advanced(UHD_LIBRARIES UHD_INCLUDE_DIRS)
