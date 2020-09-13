/*
Copyright (c) 2020  Gabriel Barbosa Gaspar Veloso and Rodrigo Brayner Lira

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef STARTING_VECTOR_INTERNAL_SIZE
#define STARTING_VECTOR_INTERNAL_SIZE 10
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

// Forward declarations
static void vector_expand_and_add_element(Vector* vector, void* address_of_element_to_add);
static size_t get_new_internal_size(Vector* vector);
static void vector_add_element_without_expanding(Vector* vector, void* address_of_element_to_add);


void vector_add(Vector* vector, void* address_of_element_to_add) {
	if (vector -> size == vector -> internal_size)
		vector_expand_and_add_element(vector, address_of_element_to_add);
	else vector_add_element_without_expanding(vector, address_of_element_to_add);
}

static void vector_expand_and_add_element(Vector* vector, void* address_of_element_to_add) {
	size_t new_internal_size = get_new_internal_size(vector);
	void** new_pointers = calloc(new_internal_size, sizeof(void*));

	memcpy(new_pointers, vector -> pointers, (vector -> size) * sizeof(void*));
	vector -> internal_size = new_internal_size;

	free(vector -> pointers);
	vector -> pointers = new_pointers;
	vector_add_element_without_expanding(vector, address_of_element_to_add);
}

static size_t get_new_internal_size(Vector* vector) {
	size_t current_size = vector -> internal_size;
	return current_size != 0 ? 2 * current_size : STARTING_VECTOR_INTERNAL_SIZE;
}

static void vector_add_element_without_expanding(Vector* vector, void* address_of_element_to_add) {
	vector -> pointers[vector -> size++] = address_of_element_to_add;
}

void vector_free(Vector* vector) {
	free(vector -> pointers);
	free(vector);
}

void* vector_get(Vector* vector, size_t index) {
	return vector -> pointers[index];
}

Vector* vector_create() {
	Vector* vector = malloc(sizeof(Vector));

	vector -> size = 0;
	vector -> internal_size = 0;
	vector -> pointers = NULL;

	return vector;
}
