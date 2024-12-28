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
#include <queue>
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

void test_case(void) {
	long n, k;
	std::cin >> n >> k;

	long luck = 0;
	std::queue<std::pair<long, long>> fila;
	fila.push({ 1, n });
	while (!fila.empty()) {
		auto [l, r] = fila.front();
		fila.pop();

		if ((r - l + 1) < k) {
			continue;
		}

		long m = (l + r) / 2;
		if ((r - l + 1) & 1 == 0) {
			fila.push({ l, m });
			fila.push({ m + 1, r });
		}
		else {
			luck += m;
			if (l == r) continue;
			fila.push({ l, m - 1 });
			fila.push({ m + 1, r });
		}
	}

	std::cout << luck << std::endl;
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
