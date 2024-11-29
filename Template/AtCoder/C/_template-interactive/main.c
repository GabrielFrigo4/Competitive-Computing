#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void test_case(long t) {
	return;
}

int main(void) {
	long t;
	while (scanf("%li", &t)) {
		test_case(t);
	}
	return 0;
}
