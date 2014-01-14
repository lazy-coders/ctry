CTRY
====

Introduction
------------

CTRY is an impementation of exceptions in C language. It simulates the
functionallity of try-catch system of C++ to simplify the error management in
code and improve the code legibility.

How to use
----------

```c
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
```

Plannification
--------------

- [X] Very basic CTRY exception system.
- [ ] Personalized exceptions.
- [ ] Finally block implementation.
- [ ] Basic I/O with exception support.
- [ ] Multithread support.
