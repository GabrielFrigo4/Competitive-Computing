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
#include <string>
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
#define ALFABETO_SIZE ('z'-'a'+1)
#define ALFABETO_INDEX(c) (c - 'a')
#pragma endregion Custom

std::string s;
std::vector<uint> st;

void make_st(const int i, const int l, const int r) {
	if (l == r) {
		st[i] = 0;
		st[i] += 1 << ALFABETO_INDEX(s[l]);
		return;
	}

	const int mid = (l + r) / 2;
	make_st(2 * i, l, mid);
	make_st(2 * i + 1, mid + 1, r);
	st[i] = st[2 * i] | st[2 * i + 1];
}

void set_st(const int pos, const char c, const int i, const int l, const int r) {
	if (l == r) {
		st[i] = 0;
		st[i] += 1 << ALFABETO_INDEX(c);
		return;
	}

	const int mid = (l + r) / 2;
	if (pos <= mid) {
		set_st(pos, c, 2 * i, l, mid);
	}
	else {
		set_st(pos, c, 2 * i + 1, mid + 1, r);
	}

	st[i] = st[2 * i] | st[2 * i + 1];
}

uint get_st(const int gl, const int gr, const int i, const int l, const int r) {
	if (l > gr || r < gl) {
		return 0;
	}
	if (l >= gl && r <= gr) {
		return st[i];
	}

	const int mid = (l + r) / 2;
	uint left = get_st(gl, gr, 2 * i, l, mid);
	uint right = get_st(gl, gr, 2 * i + 1, mid + 1, r);

	return left | right;
}

void query_set(const int pos, const char c) {
	set_st(pos - 1, c, 1, 0, s.length() - 1);
}

int query_get(const int l, const int r) {
	uint chunk = get_st(l - 1, r - 1, 1, 0, s.length() - 1);
	return std::popcount(chunk);
}

void test_run(void) {
	std::cin >> s;
	st.resize(4 * s.length());
	make_st(1, 0, s.length() - 1);

	int q;
	std::cin >> q;

	while(q--) {
		int t;
		std::cin >> t;

		switch (t) {
			case 1:
			{
				int  pos;
				char c;
				std::cin >> pos >> c;
				query_set(pos, c);
				break;
			}
			case 2:
			{
				int l, r;
				std::cin >> l >> r;
				std::cout << query_get(l, r) << std::endl;
				break;
			}
		}
	}
	return;
}

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	test_run();
	return 0;
}
