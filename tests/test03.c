#include <ctry.h>
#include <stdio.h>

#define TRY01     1
#define TRY02     2

int main(void) {
	int ret = 3;
	CTRY {
		CTRY {
			printf("Throwing error inside double CTRY body...");
			CTHROW(1);
		}
		CCATCH(1) {
			printf(" 1. Error catched\n");
			ret &= ~TRY01;
		}
		CENDTRY;

		printf("Throwing error inside CTRY body...");
		CTHROW(1);
	}
	CCATCH(1) {
		printf("2. Error catched\n");
		ret &= ~TRY02;
	}
	CENDTRY;

	return ret;
}

// vim:ts=4:sw=4:cindent

