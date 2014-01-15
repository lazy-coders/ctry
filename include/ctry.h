/* ctry - exception system for C language.
 * Copyright (C) 2013 Samuel Rodriguez Sevilla <laparca {at} laparca.es>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __CTRY_H__
#define __CTRY_H__

#include <setjmp.h>
#include <stdlib.h>

extern jmp_buf __ctry_jmp_data;

#define CTRY                             \
do {                                     \
	switch(setjmp(__ctry_jmp_data)) {    \
		case 0:                          \
			__ctry_push_jmp_state();     \
			do {

#define CCATCH(ex)                       \
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

// vim:ts=4:sw=4:cindent

