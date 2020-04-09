/* SPDX-License-Identifier: MIT */
/*
 * Copyright (C) 2015-2020 Micron Technology, Inc.  All rights reserved.
 */

#ifndef MPOOL_UTIL_LOG2_H
#define MPOOL_UTIL_LOG2_H

#include <stdbool.h>
#include <assert.h>
#include <sys/param.h>

static inline __attribute__((const))
unsigned int
ilog2(unsigned long n)
{
	assert(n > 0);

	return (NBBY * sizeof(n) - 1) - __builtin_clzl(n);
}

static inline __attribute__((const))
bool
is_power_of_2(unsigned long n)
{
	return n > 0 && !(n & (n - 1));
}

static inline __attribute__((const))
unsigned long
roundup_pow_of_two(unsigned long n)
{
	if (n == 1)
		return 1;

	return (1UL << (ilog2(n - 1) + 1));
}

static inline __attribute__((const))
unsigned long
rounddown_pow_of_two(unsigned long n)
{
	return (1UL << ilog2(n));
}

#define order_base_2(_n)    ilog2(roundup_pow_of_two((_n)))

#endif /* MPOOL_UTIL_LOG2_H */
