#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdint>
#include <cstddef>
#include <climits>
#include <cstring>
#include <cctype>

#include <string>
#include <set>

void test_case(void) {
	int64_t n, a, b;
	std::cin >> n >> a >> b;

	std::string s;
	std::cin >> s;

	std::pair<int64_t, int64_t> current_pos = {0, 0};
	std::set<std::pair<int64_t, int64_t>> pos = {current_pos};
	for (size_t i = 0; i < s.length(); i++) {
		switch (s[i]) {
			case 'N':
				current_pos = {std::get<0>(current_pos), std::get<1>(current_pos) + 1};
				break;
			case 'E':
				current_pos = {std::get<0>(current_pos) + 1, std::get<1>(current_pos)};
				break;
			case 'S':
				current_pos = {std::get<0>(current_pos), std::get<1>(current_pos) - 1};
				break;
			case 'W':
				current_pos = {std::get<0>(current_pos) - 1, std::get<1>(current_pos)};
				break;
		}
		pos.insert(current_pos);
	}

	if (pos.contains({a, b})) {
		std::cout << "YES" << std::endl;
	}
	else if (std::get<0>(current_pos) < 0 || std::get<1>(current_pos) < 0) {
		std::cout << "NO" << std::endl;
	}
	else if (current_pos == std::make_pair(0, 0)) {
		std::cout << (current_pos == std::make_pair(a, b) ? "YES" : "NO") << std::endl;
	}
	else if (std::get<0>(current_pos) == 0) {
		std::cout << (pos.contains({a, b % std::get<1>(current_pos)}) ? "YES" : "NO") << std::endl;
	}
	else if (std::get<1>(current_pos) == 0) {
		std::cout << (pos.contains({a % std::get<0>(current_pos), b}) ? "YES" : "NO") << std::endl;
	}
	else {
		int64_t min_div = std::min(a / std::get<0>(current_pos), b / std::get<1>(current_pos));
		std::pair<int64_t, int64_t> pair_rest = {a - std::get<0>(current_pos) * min_div, b - std::get<1>(current_pos) * min_div};
		std::cout << (pos.contains(pair_rest) ? "YES" : "NO") << std::endl;
	}
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int64_t t;
	std::cin >> t;

	while (t-- > 0) {
		test_case();
	}
	return 0;
}