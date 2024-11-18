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

bool equation(const int64_t n, const int64_t w, const int64_t b, const int64_t x) {
	return ((-w * x + n) % b == 0);
}

bool assert(const int64_t n, const int64_t w, const int64_t b) {
	if (w + b == 0) {
		if (n == 0) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "0" << std::endl;
		}
		return true;
	}
	if (w == 0) {
		if (n % b == 0) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "0" << std::endl;
		}
		return true;
	}
	if (b == 0) {
		if (n % w == 0) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "0" << std::endl;
		}
		return true;
	}
	return false;
}

void test_run(void) {
	int64_t n, w, b;
	std::cin >> n >> w >> b;

	if (assert(n, w, b)) {
		return;
	}

	const int64_t min_x = 0;
	const int64_t max_x = n/w;

	int64_t p1 = -1, p2 = -1;
	for (int64_t x = min_x; x <= max_x; x++) {
		bool ok = equation(n, w, b, x);

		if (ok && p1 == -1) {
			p1 = x;
			continue;
		}
		if (ok && p2 == -1) {
			p2 = x;
			break;
		}
	}

	if (p1 == -1) {
		std::cout << "0" << std::endl;
		return;
	}
	if (p2 == -1) {
		std::cout << "1" << std::endl;
		return;
	}

	const int64_t delta = p2 - p1;
	const int64_t count = (max_x + delta - p1) / delta;

	std::cout << count << std::endl;
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
