#ifndef MASTERMIND_UTIL_INTRINSIC_HPP
#define MASTERMIND_UTIL_INTRINSIC_HPP

#ifdef _WIN32
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

namespace util { namespace intrinsic {

inline unsigned int rotate_left(unsigned int value, int shift)
{
	return _rotl(value, 4);
}

inline int bit_scan_reverse(unsigned int value)
{
	unsigned long pos = 0;
#ifdef _WIN32
	_BitScanReverse(&pos, value);
#else
	pos = 31 - __builtin_clz(value);
#endif
	return pos;
}

inline int pop_count(unsigned short a)
{
#ifdef _WIN32
#if ENABLE_SSE2
	return __popcnt16(a);
#else /* ENABLE_SSE2 */
	int n = 0;
	for (; a; a >>= 1)
	{
		n += (a & 1);
	}
	return n;
#endif
#else /* _WIN32 */
	return  __builtin_popcount(a);
#endif

}

} // namespace Intrinsic
} // namespace Utilities

#endif // MASTERMIND_UTIL_INTRINSIC_HPP
