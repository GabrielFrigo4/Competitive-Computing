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
#pragma endregion Custom

void test_run()
{
	long N, M;
	std::cin >> N >> M;

	std::vector mat(N, std::vector<long>(M));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			std::cin >> mat[y][x];
		}
	}

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			if (((y + x) & 1) != (mat[y][x] & 1))
			{
				mat[y][x]++;
			}
		}
	}

	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			std::cout << mat[y][x] << " ";
		}
		std::cout << std::endl;
	}
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
