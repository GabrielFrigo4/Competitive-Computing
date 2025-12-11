#pragma region Include
#include <algorithm>
#include <iostream>
#include <iomanip>
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
#include <vector>
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
#define INF_MIN -0x3f3f3f3f3f3f3f3fLL
#define INF_MAX 0x3f3f3f3f3f3f3f3fLL
#define INF(type) ((1LL << (sizeof(type) * 8 - 2)) - 1)
#pragma endregion Constant

#pragma region Custom
#define OFFSET (4000)
#define SIZE (2 * OFFSET + 1)
//#define DEBUG
#pragma endregion Custom

void test_case()
{
	long N;
	std::cin >> N;

	std::vector<long> a(N);
	for (auto &_a : a) {
		std::cin >> _a;
	}

	long M[4][SIZE]{};
	for (auto _a : a) {
		M[0][_a + OFFSET]++;
	}
	for (long y = 1; y < 4; y++) {
		for (auto _a : a) {
			for (long x = _a; x < SIZE; x++) {
				M[y][x] += M[y - 1][x - _a];
			}
		}
		for (long x = 0; x < SIZE; x++) {
			M[y][x] /= 2;
		}
	}

#ifdef DEBUG
	for (long y = 0; y < 4; y++) {
		for (long x = OFFSET - 1; x < OFFSET + 11; x++) {
			std::cout << M[y][x] << " ";
		}
		std::cout << std::endl;
	}
#endif

	long Q;
	std::cin >> Q;
	while (Q--) {
		long q;
		std::cin >> q;
		std::cout << M[3][q + OFFSET] << std::endl;
	}
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	long t = 1;
	//std::cin >> t;

	while (t--)
	{
		test_case();
	}
	return 0;
}
