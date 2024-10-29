#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

void test_case(int64_t t) {
	return;
}

int main(void) {
	int64_t t;
	while (scanf("%lli", &t)) {
		test_case(t);
	}
	return 0;
}
