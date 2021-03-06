#include <ctry.h>
#include <stdio.h>

int main(void) {
	int ret = 1;
	CTRY {
		printf("Throwing error inside CTRY body...");
		CTHROW(1);
	}
	CCATCH(1) {
		printf("Error catched\n");
		ret = 0;
	}
	CENDTRY;

	return ret;
}

// vim:ts=4:sw=4:cindent

