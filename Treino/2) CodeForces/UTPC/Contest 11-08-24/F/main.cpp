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

#include <vector>

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
	if (std::min(w, b) == 0) {
		if (n % std::max(w, b) == 0) {
			std::cout << "1" << std::endl;
		}
		else {
			std::cout << "0" << std::endl;
		}
		return true;
	}
	return false;
}

int64_t get_fist_pos(const int64_t n, const int64_t w, const int64_t b) {
	const int64_t jump = w % b;
	const int64_t finish_line = n % b;

	if (jump == 0) {
		return -(finish_line != 0);
	}

	if (finish_line % jump == 0) {
		return finish_line / jump;
	}

	int64_t big_jump = jump;
	std::vector<std::pair<int64_t, int64_t>> jumps = {std::make_pair(big_jump, 1)};
	while (big_jump > std::gcd(b, big_jump) && finish_line % big_jump != 0) {
		const int64_t lenght = (b / big_jump) + 1;
		big_jump = (lenght * big_jump) % b;
		jumps.push_back(std::make_pair(big_jump, lenght * std::get<1>(jumps.back())));
	}

	if (finish_line % big_jump != 0) {
		return -1;
	}

	int64_t fist_pos = 0;
	int64_t jump_pos = 0;
	for (const auto jmp : jumps) {
		while (jump_pos + std::get<0>(jmp) <= finish_line) {
			jump_pos += std::get<0>(jmp);
			fist_pos += std::get<1>(jmp);
		}

		if (jump_pos == finish_line) {
			break;
		}
	}
	return fist_pos;
}

void test_run(void) {
	int64_t n, w, b;
	std::cin >> n >> w >> b;

	if (assert(n, w, b)) {
		return;
	}

	const std::pair<int64_t, int64_t> limits = {0, n / w};
	const int64_t delta = b / std::gcd(w, b);

	const int64_t fist_pos = get_fist_pos(n, w, b);
	if (fist_pos == -1) {
		std::cout << "0" << std::endl;
		return;
	}

	const int64_t count = (std::get<1>(limits) + delta - fist_pos) / delta;
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
