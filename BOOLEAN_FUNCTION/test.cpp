#include "test.h"
#include "boolean_function.h"
#include <iostream>


	int main()
	{
		RUN_TEST(test_ctor0, "successed");
		RUN_TEST(test_ctor1, "successed");
		RUN_TEST(test_ctor2, "successed");
		RUN_TEST(test_ctor3, "successed");
		RUN_TEST(test_from_anf, "successed");
		RUN_TEST(test_ctor_string, "successed");
		RUN_TEST(test_ctor_vec, "successed");
		RUN_TEST(test_ctor_copy, "successed");

		RUN_TEST(test_op_xor, "successed");
		RUN_TEST(test_op_and, "successed");
		RUN_TEST(test_op_or, "successed");
		RUN_TEST(test_op_not, "successed");

		RUN_TEST(test_op_eq, "successed");
		RUN_TEST(test_op_more, "successed");

		RUN_TEST(test_it, "successed");
		RUN_TEST(test_it_begin_end, "successed");
		RUN_TEST(test_access, "successed");

		RUN_TEST(test_property, "successed");
		RUN_TEST(test_property1, "successed");
		RUN_TEST(test_property2, "successed");

		RUN_TEST(test_anf, "successed");

		RUN_TEST(test_const, "successed");

		RUN_TEST(test_calc, "successed");
		RUN_TEST(test_combo, "successed");
		RUN_TEST(test_combo2, "successed");
		system("pause");
		return 0;
	}
