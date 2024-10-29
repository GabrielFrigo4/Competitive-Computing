#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

void test_case(void) {
	return;
}

int main(void) {
	int64_t t;
	scanf("%lli", &t);

	while (t-- > 0) {
		test_case();
	}
	return 0;
}
