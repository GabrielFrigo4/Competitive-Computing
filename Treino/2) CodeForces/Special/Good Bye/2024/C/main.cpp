#pragma region Default-Include
#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#pragma endregion Default-Include

#pragma region Include
#pragma endregion Include

#pragma region Default-Define
#define sbyte int8_t
#define short int16_t
#define int int32_t
#define long int64_t
#define byte uint8_t
#define ushort uint16_t
#define uint uint32_t
#define ulong uint64_t
#pragma endregion Default-Define

#pragma region Define
#pragma endregion Define

long get_luck(const int l, const int r, const int k) {
	const int m = (l + r) / 2;
	const int s = r - l + 1;
	if (k > s) return 0;

	long luck = 0;
	if (s & 1 == 1) {
		luck += m;
		
		if (l == r) return m;
		luck += get_luck(l, m - 1, k);
		luck += get_luck(m + 1, r, k);	
	}
	else {
		luck += get_luck(l, m, k);
		luck += get_luck(m + 1, r, k);
	}
	return luck;
}

void test_case(void) {
	long n, k;
	std::cin >> n >> k;

	std::cout << get_luck(1, n, k) << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t;
	std::cin >> t;

	while (t--) {
		test_case();
	}
	return 0;
}
