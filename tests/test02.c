#include <ctry.h>
#include <stdio.h>

int test_div(int a, int b) {
	if (b == 0)
		CTHROW(1);
	return a / b;
}

int main(void) {
	int ret = 1;
	CTRY {
		printf("Indirect throwing of error inside CTRY body...");
		test_div(1, 0);
	}
	CCATCH(1) {
		printf("Error catched\n");
		ret = 0;
	}
	CENDTRY;

	return ret;
}

// vim:ts=4:sw=4:cindent

