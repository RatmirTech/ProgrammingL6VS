#pragma once
using ullong = unsigned long long;

namespace constants {
	const ullong sizeLongLong = sizeof(unsigned long long) << 3;
	const ullong maxValue = ~0ULL;
	const ullong lastBitMask = 0x8000000000000000ULL;
	const ullong firstBitMask = 1ULL;
	const ullong oddBitsMask = 0x5555555555555555ULL;
	const ullong evenBitsMask = oddBitsMask << 1;
}