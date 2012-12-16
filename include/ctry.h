#ifndef __CTRY_H__
#define __CTRY_H__

#include <setjmp.h>

#define CTRY     
#define CCATCH
#define CENDTRY
#define CTHROW


do {
	switch(setjmp(__ctry_jmp_inf)) {
		case 0:
			__push_jmp_state();
			do {
				/*Our normal code */
			} while(0);
			__pop_jmp_state();
			break;

		case 1:
			__pop_jmp_state();
			do {
				/* Exception treatment */
			} while(0);

		default:
	}
}while(0);


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif

#endif

