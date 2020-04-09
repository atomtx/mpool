/* SPDX-License-Identifier: MIT */
/*
 * Copyright (C) 2015-2020 Micron Technology, Inc.  All rights reserved.
 */

#ifndef MPOOL_UTIL_BYTEORDER_H
#define MPOOL_UTIL_BYTEORDER_H

#define __BSD_SOURCE

#include <stdint.h>
#include <endian.h>

/*
 * Using static inlines instead of simple macro definitions
 * works better with bullseye code coverage.
 */
static __always_inline uint16_t cpu_to_le16(uint16_t x) { return htole16(x); }
static __always_inline uint32_t cpu_to_le32(uint32_t x) { return htole32(x); }
static __always_inline uint64_t cpu_to_le64(uint64_t x) { return htole64(x); }

static __always_inline uint16_t le16_to_cpu(uint16_t x) { return le16toh(x); }
static __always_inline uint32_t le32_to_cpu(uint32_t x) { return le32toh(x); }
static __always_inline uint64_t le64_to_cpu(uint64_t x) { return le64toh(x); }

static __always_inline uint16_t cpu_to_be16(uint16_t x) { return htobe16(x); }
static __always_inline uint32_t cpu_to_be32(uint32_t x) { return htobe32(x); }
static __always_inline uint64_t cpu_to_be64(uint64_t x) { return htobe64(x); }

static __always_inline uint16_t be16_to_cpu(uint16_t x) { return be16toh(x); }
static __always_inline uint32_t be32_to_cpu(uint32_t x) { return be32toh(x); }
static __always_inline uint64_t be64_to_cpu(uint64_t x) { return be64toh(x); }

#endif /* MPOOL_UTIL_BYTEORDER_H */
