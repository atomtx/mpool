#
# SPDX-License-Identifier: MIT
#
# Copyright (C) 2015-2020 Micron Technology, Inc.  All rights reserved.
#

message(STATUS "Configuring mpool in ${CMAKE_CURRENT_SOURCE_DIR}")

MPOOL_EXECUTABLE2(
  NAME
    mptest

  SRCS
    mptest.c

  INCLUDES
    ${MPOOL_INCLUDE_DIRS}
    ${MPOOL_UTIL_DIR}/include

  LINK_LIBS
    mpool-solib

  COMPONENT
    test
)
