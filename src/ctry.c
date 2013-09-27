#include <ctry.h>


extern jmp_buff __ctry_jmp_data;

struct __ctry_stack {
	struct __ctry_stack next;
	jmp_buff            jmp_data;
};

typedef struct __ctry_stack __ctry_stack;

static __ctry_stack* ctry_stack = NULL;

/**
 * Push the stack state obteined in setjmp.
 */
void __ctry_push_jmp_state() {
	__ctry_stack* node;
	node = (__ctry_stack*)malloc(sizeof(__ctry_stack));
	if (!node) {
		abort();
	}

	node->next = ctry_stack;
	node->jmp_data = __ctry_jmp_data;
	ctry_stack = node;
}

/**
 * Pops the stack state.
 */
void __ctry_pop_jmp_state() {
	__ctry_stack* node;

	node = __ctry_stack;
	__ctry_stack = node->next;

	__ctry_jmp_data = node->jmp_data;

	free(node);
}

/**
 * Tests if the code is insede of some CTRY block.
 * @return !0 if the code is inside a ctry blocke directly or indirectly.
 */
int inside_ctry_block() {
	return ctry_stack != NULL;	
}
