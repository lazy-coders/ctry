CTRY
====

Introduction
------------

CTRY is an impementation of exceptions in C language. It simulates the
functionallity of try-catch system of C++ to simplify the error management in
code and improve the code legibility.

How to use
----------

	CTRY {
		if ((file = fopen("somefile.txt", "rb")) == NULL)
			CTHROW(1);

		if (fwrite("Hello", 5, 1, file) != 1)
			CTHROW(1);

		fclose(file);
	}
	CATCH(x) {
		fprintf(stderr, "IO error!\n");
		exit(1);
	}
	CENDTRY;

Plannification
--------------

1. ~~Very basic CTRY exception system.~~
2. Personalized exceptions.
3. Finally block implementation.
4. Basic I/O with exception support.
5. Multithread support.
