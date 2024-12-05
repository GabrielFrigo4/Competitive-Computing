#pragma region Default-Include
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
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

void test_case(long t) {
	return;
}

int main(void) {
	long t;
	while (scanf("%lli", &t)) {
		test_case(t);
	}
	return 0;
}
