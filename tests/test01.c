#include <ctry.h>
#include <stdio.h>

int main(void) {
	CTRY {
		printf("Throwing error inside CTRY body...");
		CTHROW(1);
	}
	CCATCH {
		printf("Error catched\n");
	}
	CENDTRY;

	return 0;
}

// vim:ts=4:sw=4:cindent

