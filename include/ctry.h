#ifndef __CTRY_H__
#define __CTRY_H__

#include <setjmp.h>

extern jmp_buf __ctry_jmp_data;

#define CTRY                             \
do {                                     \
	switch(setjmp(__ctry_jmp_inf)) {     \
		case 0:                          \
			__ctry_push_jmp_state();     \
			do {

#define CCATCH                           \
			} while(0);                  \
			__ctry_pop_jmp_state();      \
			break;                       \
		case 1:                          \
			__ctry_pop_jmp_state();      \
			do {

#define CENDTRY                          \
			} while(0);                  \
			break;                       \
	}                                    \
}while(0);

#define CTHROW(x)                        \
do {                                     \
	if (inside_ctry_block()) {           \
		longjmp(__ctry_jmp_data, 1);     \
	}                                    \
	else {                               \
		abort();                         \
	}                                    \
} while(0)

/*
do {
	switch(setjmp(__ctry_jmp_data)) {
		case 0:
			__ctry_push_jmp_state();
			do {
				// Our normal code
			} while(0);
			__ctry_pop_jmp_state();
			break;

		case 1:
			__ctry_pop_jmp_state();
			do {
				// Exception treatment
			} while(0);

		default:
	}
}while(0);
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Push the stack state obteined in setjmp.
 */
void __ctry_push_jmp_state();

/**
 * Pops the stack state.
 */
void __ctry_pop_jmp_state();

/**
 * Tests if the code is insede of some CTRY block.
 * @return !0 if the code is inside a ctry blocke directly or indirectly.
 */
int inside_ctry_block();

#ifdef __cplusplus
}
#endif

#endif

