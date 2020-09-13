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

#include <stdlib.h>
#include "minunit.h"
#include "vector.h"

MU_TEST(vector_is_instantiable) {
	// Test is a failure if it won't compile
	Vector* vector = vector_create();

	vector_free(vector);

	mu_check(1);
}

MU_TEST(vector_has_size) {
	// Test is a failure if it won't compile
	Vector* vector = vector_create();

	size_t size_of_vector = vector -> size;

	vector_free(vector);

	mu_check(1);
}

MU_TEST(vector_create_function_exists) {
	// Test is a failure if it won't compile
	Vector* vector = vector_create();

	vector_free(vector);

	mu_check(1);
}

MU_TEST(destroy_basic_vector_function_exists) {
	// Test is a failure if it won't compile
	Vector* vector = vector_create();

	vector_free(vector);

	mu_check(1);
}

MU_TEST(basic_vector_starts_with_size_zero) {
	Vector* vector = vector_create();

	size_t vector_size = vector -> size;

	vector_free(vector);

	mu_assert(vector_size == 0, "Initial basic vector size is non-zero");
}

MU_TEST(can_add_one_element_to_vector) {
	// Test is a failure if it won't compile
	Vector* vector = vector_create();
	int* pointer_to_int = malloc(sizeof(int));

	vector_add(vector, pointer_to_int);

	vector_free(vector);
	free(pointer_to_int);

	mu_check(1);
}

MU_TEST(can_get_one_element_from_vector) {
	Vector* vector = vector_create();
	int* pointer_to_int = malloc(sizeof(int));
	
	vector_add(vector, pointer_to_int);

	int* pointer_to_returned_int = vector_get(vector, 0);

	int original_int = *pointer_to_int;
	int returned_int = *pointer_to_returned_int;

	free(pointer_to_int);
	vector_free(vector);

	mu_assert(
		original_int == returned_int,
		"Value of returned int different from given"
	);
}

MU_TEST(size_grows_to_one) {
	Vector* vector = vector_create();
	
	size_t old_size = vector -> size;

	int* pointer_to_int = malloc(sizeof(int));
	vector_add(vector, pointer_to_int);

	size_t new_size = vector -> size;

	free(pointer_to_int);
	vector_free(vector);
	
	mu_assert(
		new_size == old_size + 1,
		"New size not equals old size plus one."
	);
}

MU_TEST(can_get_more_than_one_element) {
	Vector* vector = vector_create();

	int* first_element = malloc(sizeof(int));
	int* second_element = malloc(sizeof(int));

	*first_element = 10;
	*second_element = 20;

	vector_add(vector, first_element);
	vector_add(vector, second_element);

	int* first_returned_element = vector_get(vector, 0);
	int* second_returned_element = vector_get(vector, 1);

	int first_comparison = *first_element == *first_returned_element;
	int second_comparison = *second_element == *second_returned_element;

	char firstMessage[50], secondMessage[50];

	sprintf(firstMessage, "First unequal. Given: %d, Returned: %d", *first_element, *first_returned_element);
	sprintf(secondMessage, "Second unequal. Given: %d, Returned: %d", *second_element, *second_returned_element);

	vector_free(vector);
	free(first_element);
	free(second_element);

	mu_assert(first_comparison, firstMessage);
	mu_assert(second_comparison, secondMessage);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(vector_is_instantiable);
	MU_RUN_TEST(vector_has_size);
	MU_RUN_TEST(vector_create_function_exists);
	MU_RUN_TEST(destroy_basic_vector_function_exists);
	MU_RUN_TEST(basic_vector_starts_with_size_zero);
	MU_RUN_TEST(can_add_one_element_to_vector);
	MU_RUN_TEST(can_get_one_element_from_vector);
	MU_RUN_TEST(size_grows_to_one);
	MU_RUN_TEST(can_get_more_than_one_element);
}

int main(void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
