#include <ctry.h>
#include <stdio.h>

int main(void) {
	int ret = 2;
	CTRY {
		CTRY {
			printf("Throwing error inside double CTRY body...");
			CTHROW(1);
		}
		CCATCH(1) {
			printf(" 1. Error catched\n");
			ret --;
		}
		CENDTRY;

		printf("Throwing error inside CTRY body...");
		CTHROW(1);
	}
	CCATCH(1) {
		printf("2. Error catched\n");
		ret --;
	}
	CENDTRY;

	return ret;
}

// vim:ts=4:sw=4:cindent

