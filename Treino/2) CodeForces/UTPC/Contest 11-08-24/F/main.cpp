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

bool assert(const int64_t n, const int64_t w, const int64_t b)
{
	if (w + b == 0)
	{
		if (n == 0)
		{
			std::cout << "1" << std::endl;
		}
		else
		{
			std::cout << "0" << std::endl;
		}
		return true;
	}
	if (std::min(w, b) == 0)
	{
		if (n % std::max(w, b) == 0)
		{
			std::cout << "1" << std::endl;
		}
		else
		{
			std::cout << "0" << std::endl;
		}
		return true;
	}
	return false;
}

int64_t gcd_ex(const int64_t a, const int64_t b, std::pair<int64_t, int64_t> &pos)
{
	if (b == 0)
	{
		std::get<0>(pos) = 1;
		std::get<1>(pos) = 0;
		return a;
	}
	std::pair<int64_t, int64_t> pos1;
	int64_t d = gcd_ex(b, a % b, pos1);
	std::get<0>(pos) = std::get<1>(pos1);
	std::get<1>(pos) = std::get<0>(pos1) - std::get<1>(pos1) * (a / b);
	return d;
}

void test_run(void)
{
	int64_t n, w, b;
	std::cin >> n >> w >> b;

	if (assert(n, w, b))
	{
		return;
	}

	const int64_t min_x = 0;
	const int64_t max_x = n / w;

	std::pair<int64_t, int64_t> pos;
	const int64_t mdc = gcd_ex(w, b, pos);
	const int64_t delta = b / mdc;
	std::get<0>(pos) *= n / mdc;
	std::get<1>(pos) *= n / mdc;

	if (n % mdc != 0)
	{
		std::cout << "0" << std::endl;
		return;
	}

	int64_t first_x = std::get<0>(pos) % delta;
	if (first_x < 0)
	{
		first_x += delta;
	}
	const int64_t count = (max_x + delta - first_x) / delta;
	std::cout << count << std::endl;
	return;
}

int main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
