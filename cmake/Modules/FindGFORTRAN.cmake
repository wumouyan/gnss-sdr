# Copyright (C) 2011-2020  (see AUTHORS file for a list of contributors)
#
# GNSS-SDR is a software-defined Global Navigation Satellite Systems receiver
#
# This file is part of GNSS-SDR.
#
# SPDX-License-Identifier: GPL-3.0-or-later

if(NOT COMMAND feature_summary)
    include(FeatureSummary)
endif()

if(NOT GFORTRAN_ROOT)
    set(GFORTRAN_ROOT_USER_DEFINED /usr/lib)
else()
    set(GFORTRAN_ROOT_USER_DEFINED ${GFORTRAN_ROOT})
endif()
if(DEFINED ENV{GFORTRAN_ROOT})
    set(GFORTRAN_ROOT_USER_DEFINED
        ${GFORTRAN_ROOT_USER_DEFINED}
        $ENV{GFORTRAN_ROOT}
    )
endif()

find_library(GFORTRAN NAMES gfortran
    PATHS ${GFORTRAN_ROOT_USER_DEFINED}
        /usr/lib64
        /usr/lib/gcc/x86_64-linux-gnu
        /usr/lib/gcc/i686-linux-gnu
        /usr/lib/gcc/i386-linux-gnu
        /usr/lib/gcc/x86_64-linux-gnu/4.6 # Ubuntu 12.04
        /usr/lib/gcc/i686-linux-gnu/4.6
        /usr/lib/gcc/x86_64-linux-gnu/4.7
        /usr/lib/gcc/i686-linux-gnu/4.7
        /usr/lib/gcc/x86_64-linux-gnu/4.8
        /usr/lib/gcc/i686-linux-gnu/4.8
        /usr/lib/gcc/x86_64-linux-gnu/4.9
        /usr/lib/gcc/i686-linux-gnu/4.9
        /usr/lib/gcc/x86_64-redhat-linux/4.7.2 # Fedora 18
        /usr/lib/gcc/i686-redhat-linux/4.7.2
        /usr/lib/gcc/x86_64-redhat-linux/4.8.1 # Fedora 19
        /usr/lib/gcc/x86_64-redhat-linux/4.8.3 # Fedora 20
        /usr/lib/gcc/x86_64-redhat-linux/4.9.1 # Fedora 21
        /usr/lib/gcc/i686-redhat-linux/4.8.1
        /usr/lib/gcc/i686-redhat-linux/4.8.3
        /usr/lib/gcc/i686-redhat-linux/4.9.1
        /usr/lib/gcc/x86_64-redhat-linux/4.4.4 # CentOS 6
        /usr/lib/gcc/i686-redhat-linux/4.4.4
        /usr/lib/gcc/x86_64-redhat-linux/4.8.2
        /usr/lib/gcc/i686-redhat-linux/4.8.2
        /usr/lib/gcc/x86_64-redhat-linux/7
        /usr/lib/gcc/i686-redhat-linux/7
        /usr/lib/gcc/x86_64-redhat-linux/8
        /usr/lib/gcc/i686-redhat-linux/8
        /usr/lib/gcc/x86_64-redhat-linux/9
        /usr/lib/gcc/i686-redhat-linux/9
        /usr/lib64/gcc/x86_64-redhat-linux/7
        /usr/lib64/gcc/x86_64-redhat-linux/8
        /usr/lib64/gcc/x86_64-redhat-linux/9
        /usr/lib/gcc/armv7hl-redhat-linux-gnueabi/7
        /usr/lib/gcc/aarch64-redhat-linux/7
        /usr/lib/gcc/i586-suse-linux/4.8  # OpenSUSE 13.1
        /usr/lib/gcc/i586-suse-linux/4.9
        /usr/lib/gcc/i586-suse-linux/7
        /usr/lib/gcc/i586-suse-linux/8
        /usr/lib/gcc/i586-suse-linux/9
        /usr/lib/gcc/x86_64-suse-linux/4.8
        /usr/lib/gcc/x86_64-suse-linux/4.9
        /usr/lib64/gcc/x86_64-suse-linux/7
        /usr/lib64/gcc/x86_64-suse-linux/8
        /usr/lib64/gcc/x86_64-suse-linux/9
        /usr/lib/gcc/armv7hl-suse-linux-gnueabi/7
        /usr/lib/gcc/armv7hl-suse-linux-gnueabi/8
        /usr/lib/gcc/armv7hl-suse-linux-gnueabi/9
        /usr/lib64/gcc/aarch64-suse-linux/7
        /usr/lib64/gcc/aarch64-suse-linux/8
        /usr/lib64/gcc/aarch64-suse-linux/9
        /usr/lib64/gcc/powerpc64-suse-linux/7
        /usr/lib64/gcc/powerpc64-suse-linux/8
        /usr/lib64/gcc/powerpc64-suse-linux/9
        /usr/lib64/gcc/powerpc64le-suse-linux/7
        /usr/lib64/gcc/powerpc64le-suse-linux/8
        /usr/lib64/gcc/powerpc64le-suse-linux/9
        /usr/lib/gcc/i486-linux-gnu # Debian 7
        /usr/lib/gcc/i486-linux-gnu/4.4
        /usr/lib/gcc/i486-linux-gnu/4.6
        /usr/lib/gcc/i486-linux-gnu/4.7
        /usr/lib/gcc/i486-linux-gnu/4.8
        /usr/lib/gcc/i486-linux-gnu/4.9
        /usr/lib/gcc/i586-linux-gnu/4.9
        /usr/lib/gcc/arm-linux-gnueabihf/4.4 # Debian armhf
        /usr/lib/gcc/arm-linux-gnueabihf/4.5
        /usr/lib/gcc/arm-linux-gnueabihf/4.6
        /usr/lib/gcc/arm-linux-gnueabihf/4.7
        /usr/lib/gcc/arm-linux-gnueabihf/4.8
        /usr/lib/gcc/arm-linux-gnueabihf/4.9
        /usr/lib/gcc/aarch64-linux-gnu/4.9   # Debian arm64
        /usr/lib/gcc/arm-linux-gnueabi/4.7   # Debian armel
        /usr/lib/gcc/arm-linux-gnueabi/4.9
        /usr/lib/gcc/x86_64-linux-gnu/5
        /usr/lib/gcc/i686-linux-gnu/5
        /usr/lib/gcc/arm-linux-gnueabi/5
        /usr/lib/gcc/arm-linux-gnueabihf/5
        /usr/lib/gcc/aarch64-linux-gnu/5
        /usr/lib/gcc/x86_64-linux-gnu/6      # Ubuntu 16.10
        /usr/lib/gcc/alpha-linux-gnu/6
        /usr/lib/gcc/aarch64-linux-gnu/6
        /usr/lib/gcc/arm-linux-gnueabi/6
        /usr/lib/gcc/arm-linux-gnueabihf/6
        /usr/lib/gcc/hppa-linux-gnu/6
        /usr/lib/gcc/i686-gnu/6
        /usr/lib/gcc/i686-linux-gnu/6
        /usr/lib/gcc/x86_64-kfreebsd-gnu/6
        /usr/lib/gcc/i686-kfreebsd-gnu/6
        /usr/lib/gcc/m68k-linux-gnu/6
        /usr/lib/gcc/mips-linux-gnu/6
        /usr/lib/gcc/mips64el-linux-gnuabi64/6
        /usr/lib/gcc/mipsel-linux-gnu/6
        /usr/lib/gcc/powerpc-linux-gnu/6
        /usr/lib/gcc/powerpc-linux-gnuspe/6
        /usr/lib/gcc/powerpc64-linux-gnu/6
        /usr/lib/gcc/powerpc64le-linux-gnu/6
        /usr/lib/gcc/s390x-linux-gnu/6
        /usr/lib/gcc/sparc64-linux-gnu/6
        /usr/lib/gcc/x86_64-linux-gnux32/6
        /usr/lib/gcc/sh4-linux-gnu/6
        /usr/lib/gcc/x86_64-linux-gnu/7      # Debian 9 Buster
        /usr/lib/gcc/alpha-linux-gnu/7
        /usr/lib/gcc/aarch64-linux-gnu/7
        /usr/lib/gcc/arm-linux-gnueabi/7
        /usr/lib/gcc/arm-linux-gnueabihf/7
        /usr/lib/gcc/hppa-linux-gnu/7
        /usr/lib/gcc/i686-gnu/7
        /usr/lib/gcc/i686-linux-gnu/7
        /usr/lib/gcc/x86_64-kfreebsd-gnu/7
        /usr/lib/gcc/i686-kfreebsd-gnu/7
        /usr/lib/gcc/m68k-linux-gnu/7
        /usr/lib/gcc/mips-linux-gnu/7
        /usr/lib/gcc/mips64el-linux-gnuabi64/7
        /usr/lib/gcc/mipsel-linux-gnu/7
        /usr/lib/gcc/powerpc-linux-gnu/7
        /usr/lib/gcc/powerpc-linux-gnuspe/7
        /usr/lib/gcc/powerpc64-linux-gnu/7
        /usr/lib/gcc/powerpc64le-linux-gnu/7
        /usr/lib/gcc/s390x-linux-gnu/7
        /usr/lib/gcc/sparc64-linux-gnu/7
        /usr/lib/gcc/x86_64-linux-gnux32/7
        /usr/lib/gcc/sh4-linux-gnu/7
        /usr/lib/x86_64-linux-gnu         # libgfortran4
        /usr/lib/i386-linux-gnu
        /usr/lib/arm-linux-gnueabi
        /usr/lib/arm-linux-gnueabihf
        /usr/lib/aarch64-linux-gnu
        /usr/lib/i386-gnu
        /usr/lib/x86_64-kfreebsd-gnu
        /usr/lib/i386-kfreebsd-gnu
        /usr/lib/mips-linux-gnu
        /usr/lib/mips64el-linux-gnuabi64
        /usr/lib/mipsel-linux-gnu
        /usr/lib/powerpc-linux-gnu
        /usr/lib/powerpc64-linux-gnu
        /usr/lib/powerpc64le-linux-gnu
        /usr/lib/s390x-linux-gnu
        /usr/lib/sh4-linux-gnu
        /usr/lib/sparc64-linux-gnu
        /usr/lib/x86_64-linux-gnux32
        /usr/lib/alpha-linux-gnu
        /usr/lib/gcc/x86_64-linux-gnu/8     # libgfortran-8
        /usr/lib/gcc/aarch64-linux-gnu/8
        /usr/lib/gcc/arm-linux-gnueabi/8
        /usr/lib/gcc/arm-linux-gnueabihf/8
        /usr/lib/gcc/hppa-linux-gnu/8
        /usr/lib/gcc/m68k-linux-gnu/8
        /usr/lib/gcc/mips-linux-gnu/8
        /usr/lib/gcc/mips64el-linux-gnuabi64/8
        /usr/lib/gcc/mipsel-linux-gnu/8
        /usr/lib/gcc/i686-linux-gnu/8
        /usr/lib/gcc/powerpc-linux-gnuspe/8
        /usr/lib/gcc/powerpc64-linux-gnu/8
        /usr/lib/gcc/powerpc64le-linux-gnu/8
        /usr/lib/gcc/s390x-linux-gnu/8
        /usr/lib/gcc/alpha-linux-gnu/8
        /usr/lib/gcc/riscv64-linux-gnu/8
        /usr/lib/gcc/sh4-linux-gnu/8
        /usr/lib/gcc/sparc64-linux-gnu/8
        /usr/lib/gcc/x86_64-linux-gnux32/8
        /usr/lib/gcc/x86_64-kfreebsd-gnu/8
        /usr/lib/gcc/i686-kfreebsd-gnu/8
        /usr/lib/gcc/alpha-linux-gnu/9    # libgfortran-9
        /usr/lib/gcc/x86_64-linux-gnu/9
        /usr/lib/gcc/aarch64-linux-gnu/9
        /usr/lib/gcc/arm-linux-gnueabi/9
        /usr/lib/gcc/arm-linux-gnueabihf/9
        /usr/lib/gcc/i686-linux-gnu/9
        /usr/lib/gcc/powerpc64le-linux-gnu/9
        /usr/lib/gcc/powerpc64-linux-gnu/9
        /usr/lib/gcc/s390x-linux-gnu/9
        /usr/lib/gcc/hppa-linux-gnu/9
        /usr/lib/gcc/m68k-linux-gnu/9
        /usr/lib/gcc/mips-linux-gnu/9
        /usr/lib/gcc/mips64el-linux-gnuabi64/9
        /usr/lib/gcc/mipsel-linux-gnu/9
        /usr/lib/gcc/riscv64-linux-gnu/9
        /usr/lib/gcc/sh4-linux-gnu/9
        /usr/lib/gcc/sparc64-linux-gnu/9
        /usr/lib/gcc/x86_64-linux-gnux32/9
        /usr/lib/gcc/x86_64-kfreebsd-gnu/9
        /usr/lib/gcc/i686-kfreebsd-gnu/9
        /usr/lib/gcc/alpha-linux-gnu/10    # libgfortran-10
        /usr/lib/gcc/x86_64-linux-gnu/10
        /usr/lib/gcc/aarch64-linux-gnu/10
        /usr/lib/gcc/arm-linux-gnueabi/10
        /usr/lib/gcc/arm-linux-gnueabihf/10
        /usr/lib/gcc/i686-linux-gnu/10
        /usr/lib/gcc/powerpc64le-linux-gnu/10
        /usr/lib/gcc/powerpc64-linux-gnu/10
        /usr/lib/gcc/s390x-linux-gnu/10
        /usr/lib/gcc/hppa-linux-gnu/10
        /usr/lib/gcc/m68k-linux-gnu/10
        /usr/lib/gcc/mips-linux-gnu/10
        /usr/lib/gcc/mips64el-linux-gnuabi64/10
        /usr/lib/gcc/mipsel-linux-gnu/10
        /usr/lib/gcc/riscv64-linux-gnu/10
        /usr/lib/gcc/sh4-linux-gnu/10
        /usr/lib/gcc/sparc64-linux-gnu/10
        /usr/lib/gcc/x86_64-linux-gnux32/10
        /usr/lib/gcc/x86_64-kfreebsd-gnu/10
        /usr/lib/gcc/i686-kfreebsd-gnu/10
        /usr/local/lib
        /usr/local/lib64
        /usr/local/lib/i386
)

set_package_properties(GFORTRAN PROPERTIES
    URL "https://gcc.gnu.org/fortran/"
    DESCRIPTION "GNU Fortran library"
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GFORTRAN DEFAULT_MSG GFORTRAN)
