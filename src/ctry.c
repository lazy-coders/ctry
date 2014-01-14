#include <stdlib.h>
#include <string.h>
#include <ctry.h>


jmp_buf __ctry_jmp_data = {0};

struct __ctry_stack {
	struct __ctry_stack* next;
	jmp_buf              jmp_data;
};

typedef struct __ctry_stack __ctry_stack;

static __ctry_stack* ctry_stack = NULL;

/**
 * Push the stack state obteined in setjmp.
 */
void __ctry_push_jmp_state() {
	__ctry_stack* node;
	node = (__ctry_stack*)calloc(1, sizeof(__ctry_stack));
	if (!node) {
		abort();
	}

	node->next = ctry_stack;
	memcpy(node->jmp_data, __ctry_jmp_data, sizeof(__ctry_jmp_data));
	ctry_stack = node;
}

/**
 * Pops the stack state.
 */
void __ctry_pop_jmp_state() {
	__ctry_stack* node;

	node = ctry_stack;
	ctry_stack = node->next;

	free(node);

	if (ctry_stack != NULL) {
		memcpy(__ctry_jmp_data, ctry_stack->jmp_data, sizeof(__ctry_jmp_data));
	}
	else {
		memset(__ctry_jmp_data, 0, sizeof(__ctry_jmp_data));
	}
}

/**
 * Tests if the code is insede of some CTRY block.
 * @return !0 if the code is inside a ctry blocke directly or indirectly.
 */
int inside_ctry_block() {
	return ctry_stack != NULL;	
}

// vim:ts=4:sw=4:cindent

