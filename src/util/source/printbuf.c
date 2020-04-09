// SPDX-License-Identifier: MIT
/*
 * Copyright (C) 2015-2020 Micron Technology, Inc.  All rights reserved.
 */

#include <util/platform.h>
#include <util/compiler.h>
#include <util/string.h>
#include <util/printbuf.h>

#include <stdarg.h>

int
snprintf_append(
	char       *buf,
	size_t      buf_sz,
	size_t     *offset,
	const char *format,
	...)
{
	int         ret;
	va_list     args;

	va_start(args, format);
	ret = vsnprintf_append(buf, buf_sz, offset, format, args);
	va_end(args);

	return ret;
}

int
vsnprintf_append(
	char       *buf,
	size_t      buf_sz,
	size_t     *offset,
	const char *format,
	va_list     args)
{
	int     cc;

	cc = vsnprintf(buf + *offset, buf_sz - *offset, format, args);

	if (cc < 0 || cc > (buf_sz - *offset))
		*offset = buf_sz;
	else
		*offset += cc;

	return cc;
}

#ifndef MPOOL_BUILD_LIBMPOOL

int
strlcpy_append(
	char       *dst,
	const char *src,
	size_t      dstsz,
	size_t     *offset)
{
	int     cc;

	cc = strlcpy(dst + *offset, src, dstsz - *offset);

	if (cc > (dstsz - *offset))
		*offset = dstsz;
	else
		*offset += cc;

	return cc;
}

int
u64_to_string(void *dst, size_t dstsz, u64 value)
{
	const uint  base = 10;
	char       *right = dst;
	char       *left;
	int         len;

	if (dstsz < 21) /* max digits + 1 in 64 bits (base 10) */
		return 0;

	do {
		u64 tmp = value;

		value /= base;
		*right++ = '0' + tmp - value * base;
	} while (value > 0);

	len = right - (char *)dst;
	*right-- = '\000';

	left = dst;
	while (left < right) {
		char tmp = *right;

		*right-- = *left;
		*left++ = tmp;
	}

	return len;
}

int
u64_append(char *dst, size_t dstsz, u64 val, int width, size_t *offp)
{
	int n;

	if (*offp >= dstsz)
		return 0;

	dstsz -= *offp;
	dst += *offp;

	n = u64_to_string(dst, dstsz, val);

	if (n > 0 && n < dstsz) {
		if (width < 0)
			width = n + 1;

		if (n < width) {
			memmove(dst + width - n, dst, n + 1);
			memset(dst, ' ', width - n);
			*offp += width;
			n = width;
		} else {
			*offp += n;
		}
	}

	return n;
}
#endif
