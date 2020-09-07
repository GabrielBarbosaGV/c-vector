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
	Vector* vector = create_basic_vector();
	delete_basic_vector(vector);
	mu_check(1);
}

MU_TEST(vector_has_size) {
	// Test is a failure if it won't compile
	Vector* vector = create_basic_vector();
	size_t size_of_vector = vector -> size;
	delete_basic_vector(vector);
	mu_check(1);
}

MU_TEST(create_basic_vector_function_exists) {
	// Test is a failure if it won't compile
	Vector* vector = create_basic_vector();
	delete_basic_vector(vector);
	mu_check(1);
}

MU_TEST(delete_basic_vector_function_exists) {
	// Test is a failure if it won't compile
	Vector* vector = create_basic_vector();
	delete_basic_vector(vector);
	mu_check(1);
}

MU_TEST(basic_vector_starts_with_size_zero) {
	Vector* vector = create_basic_vector();
	size_t vector_size = vector -> size;
	delete_basic_vector(vector);
	mu_assert(vector_size == 0, "Initial basic vector size is non-zero");
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(vector_is_instantiable);
	MU_RUN_TEST(vector_has_size);
	MU_RUN_TEST(create_basic_vector_function_exists);
	MU_RUN_TEST(delete_basic_vector_function_exists);
	MU_RUN_TEST(basic_vector_starts_with_size_zero);
}

int main(void) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
