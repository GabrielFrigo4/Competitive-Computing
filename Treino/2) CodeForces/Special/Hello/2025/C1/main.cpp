#pragma region Include
#include <algorithm>
#include <iostream>
#include <utility>
#include <numbers>
#include <numeric>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>
#include <cmath>
#pragma endregion Include

#pragma region Library
#pragma endregion Library

#pragma region Types
#define byte uint8_t
#define short int16_t
#define int int32_t
#define long int64_t
typedef int8_t sbyte;
typedef uint16_t ushort;
typedef uint32_t uint;
typedef uint64_t ulong;
#pragma endregion Types

#pragma region Constant
#undef LONG_MIN
#undef LONG_MAX
#undef ULONG_MAX
#define SBYTE_MIN SCHAR_MIN
#define SBYTE_MAX SCHAR_MAX
#define BYTE_MAX UCHAR_MAX
#define LONG_MIN LLONG_MIN
#define LONG_MAX LLONG_MAX
#define ULONG_MAX ULLONG_MAX
#pragma endregion Constant

#pragma region Custom
#pragma endregion Custom

void test_case(void) {
	int l, r;
	std::cin >> l >> r;

	bool flag = false;
	int ml = 0, mr = 0;
	for (int i = 31; i > -1; i--) {
		switch (flag) {
			case true:
				if ((l & (1 << i)) != (r & (1 << i))) {
					ml += l & (1 << i);
					ml += r & (1 << i);
				}
				else {
					ml += (1 << i) * ((l & (1 << i)) == 0);
					mr += (1 << i) * ((r & (1 << i)) == 0);
				}
				break;
			case false:
				if ((l & (1 << i)) != (r & (1 << i))) {
					flag = true;
				}
				ml += l & (1 << i);
				mr += r & (1 << i);
				break;
		}
	}

	int m = ml;
	if (m < l) {
		m = mr;
	}
	std::cout << l << " " << m << " " << r << std::endl;
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