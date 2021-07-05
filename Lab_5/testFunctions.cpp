#include "testFunctions.h"
#include "class.h"

void lauch_tests()
{
    test_addition();
    test_substraction();
    test_division();
    test_multiplication();

    test_eqaddition();
    test_eqsubstraction();
    test_eqdivision();
    test_eqmultiplication();

    test_getters();
    test_setters();

    test_assignment();

    test_to_array();

    test_glue();

    test_iterators();
}

void cout_result (bool result)
{
    if (result)
        std::cout << "Test OK" << std::endl << std::endl;
    else
        std::cout << "Test FAIL" << std::endl << std::endl;
}

void test_addition()
{
    M_vector<int> a{1, 2, 3}, b{3, 4, 5};
    std::cout << "Addition test #1: " << std::endl << "Input data: " << a << " + " << b << std::endl << "Expected result: [4, 6, 8]" << std::endl;
    try {
        cout << "Result: " << a + b << std::endl;
        M_vector<int> answer {4, 6, 8};
        cout_result((a+b) == answer);
    } catch (except(INVALID_ADDITION)) {
        std::cout << "Vector addition fault, non-equal vectors length" << std::endl;
        cout_result(false);
    }
    a = M_vector<int>{1, 2};
    std::cout << "Addition test #2: " << std::endl << "Input data: " << a << " + " << b << std::endl << "Expected result: exception" << std::endl;
    try {
        std::cout << "Result: " << a + b << std::endl;
        cout_result(false);
    } catch (except(INVALID_ADDITION)) {
        std::cout << "Vector addition fault, non-equal vectors length" << std::endl;
        cout_result(true);
    }
}
void test_substraction()
{
    M_vector<int> a{3, 4, 5}, b{1, 2, 4};
    std::cout << "Substraction test #1: " << std::endl << "Input data: " << a << " - " << b << std::endl << "Expected result: [2, 2, 1]" << std::endl;
    try {
        std::cout << "Result: " << a - b << std::endl;
        M_vector<int> answer {2, 2, 1};
        cout_result((a - b) == answer);
    } catch (except(INVALID_SUBSTRACION)) {
        std::cout << "Vector substraction fault, non-equal vectors length" << std::endl;
        cout_result(false);
    }
    a = M_vector<int>{1, 2};
    std::cout << "Substraction test #2: " << std::endl << "Input data: " << a << " - " << b << std::endl << "Expected result: exception" << std::endl;
    try {
        std::cout << "Result: " << a - b << std::endl;
        cout_result(false);
    } catch (except(INVALID_SUBSTRACION)) {
        std::cout << "Vector substraction fault, non-equal vectors length" << std::endl;
        cout_result(true);
    }
}
void test_division()
{
    M_vector<int> a{10, 15, 25};
    int b = 5;
    std::cout << "Division test #1: " << std::endl << "Input data: " << a << " / " << b << std::endl << "Expected result: [2, 3, 5]" << std::endl;
    try {
        std::cout << "Result: " << a / b << std::endl;
        M_vector<int> answer {2, 3, 5};
        cout_result((a / b) == answer);
    } catch (except(INVALID_SUBSTRACION)) {
        std::cout << "Vector division fault, division by zero" << std::endl;
        cout_result(false);
    }
    b = 0;
    std::cout << "Division test #2: " << std::endl << "Input data: " << a << " / " << b << std::endl << "Expected result: exception" << std::endl;
    try {
        std::cout << "Result: " << a / b << std::endl;
        cout_result(false);
    } catch (except(INVALID_SUBSTRACION)) {
        std::cout << "Vector division fault, division by zero" << std::endl;
        cout_result(true);
    }
}
void test_multiplication()
{
    M_vector<int> a{2, 3, 5};
    int b = 5;
    std::cout << "Multiplication test: " << std::endl << "Input data: " << a << " * " << b << std::endl << "Expected result: [10, 15, 25]" << std::endl;
    std::cout << "Result: " << a * b << std::endl;
    M_vector<int> answer {10, 15, 25};
    cout_result((a * b) == answer);

}

void test_eqaddition()
{
    M_vector<int> a{1, 2, 3}, b{3, 4, 5};
    std::cout << "Addition with assignment test #1: " << std::endl << "Input data: " << a << " += " << b << std::endl << "Expected result: [4, 6, 8]" << std::endl;
    try {
        a += b;
        std::cout << "Result: " << a << std::endl;
        M_vector<int> answer {4, 6, 8};
        cout_result(a == answer);
    } catch (except(INVALID_ADDITION)) {
        std::cout << "Vector addition fault, non-equal vectors length" << std::endl;
        cout_result(false);
    }
    a = M_vector<int>{1, 2};
    std::cout << "Addition with assignment test #2: " << std::endl << "Input data: " << a << " += " << b << std::endl << "Expected result: exception" << std::endl;
    try {
        a += b;
        std::cout << "Result: " << a << std::endl;
        cout_result(false);
    } catch (except(INVALID_ADDITION)) {
        std::cout << "Vector addition fault, non-equal vectors length" << std::endl;
        cout_result(true);
    }
}
void test_eqsubstraction()
{
    M_vector<int> a{3, 4, 5}, b{1, 2, 4};
    std::cout << "Substraction with assignment test #1: " << std::endl << "Input data: " << a << " -= " << b << std::endl << "Expected result: [2, 2, 1]" << std::endl;
    try {
        a -= b;
        std::cout << "Result: " << a << std::endl;
        M_vector<int> answer {2, 2, 1};
        cout_result(a == answer);
    } catch (except(INVALID_SUBSTRACION)) {
        std::cout << "Vector substraction fault, non-equal vectors length" << std::endl;
        cout_result(false);
    }
    a = M_vector<int>{1, 2};
    std::cout << "Substraction with assignment test #2: " << std::endl << "Input data: " << a << " -= " << b << std::endl << "Expected result: exception" << std::endl;
    try {
        a -= b;
        std::cout << "Result: " << a << std::endl;
        cout_result(false);
    } catch (except(INVALID_SUBSTRACION)) {
        std::cout << "Vector substraction fault, non-equal vectors length" << std::endl;
        cout_result(true);
    }
}
void test_eqdivision()
{
    M_vector<int> a{10, 15, 25};
    int b = 5;
    std::cout << "Division with assignment test #1: " << std::endl << "Input data: " << a << " /= " << b << std::endl << "Expected result: [2, 3, 5]" << std::endl;
    try {
        a /= b;
        std::cout << "Result: " << a << std::endl;
        M_vector<int> answer {2, 3, 5};
        cout_result(a == answer);
    } catch (except(INVALID_SUBSTRACION)) {
        std::cout << "Vector division fault, division by zero" << std::endl;
        cout_result(false);
    }
    b = 0;
    std::cout << "Division with assignment test #2: " << std::endl << "Input data: " << a << " /= " << b << std::endl << "Expected result: exception" << std::endl;
    try {
        a /= b;
        std::cout << "Result: " << a << std::endl;
        cout_result(false);
    } catch (except(INVALID_SUBSTRACION)) {
        std::cout << "Vector division fault, division by zero" << std::endl;
        cout_result(true);
    }
}
void test_eqmultiplication()
{
    M_vector<int> a{2, 3, 5};
    int b = 5;
    std::cout << "Multiplication with assignment test: " << std::endl << "Input data: " << a << " *= " << b << std::endl << "Expected result: [10, 15, 25]" << std::endl;
    a *= b;
    std::cout << "Result: " << a << std::endl;
    M_vector<int> answer {10, 15, 25};
    cout_result(a == answer);
}

void test_getters()
{
    M_vector<int> vector{1, 2, 3};
    std::cout << "Getters test: " << std::endl << "Input data: " << vector << std::endl << "Expected results:" << std::endl << "vector.get_elem(0) - 1" << std::endl
         << "vector.get_elem(3) - exception" << std::endl << "vector[0] - 1" << std::endl << "vector[3] - exception" << std::endl << "vector.get_length() - 3" << std::endl << std::endl;
    std::cout << "Results:" << std::endl;

    try {
        int result = 1;
        std::cout << "vector.get_elem(0) - " << vector.get_elem(0) << std::endl;
        cout_result(vector.get_elem(0) == result);
    } catch (except(ELEMENT_NOT_EXIST)) {
        std::cout << "Element getting fault. Index is not in vector" << std::endl;
        cout_result(false);
    }

    try {
        std::cout << "vector.get_elem(3) - " << vector.get_elem(3) << std::endl;
        cout_result(false);
    } catch (except(ELEMENT_NOT_EXIST)) {
        std::cout << "Element getting fault. Index is not in vector" << std::endl;
        cout_result(true);
    }

    try {
        int result = 1;
        std::cout << "vector[0] - " << vector[0] << std::endl;
        cout_result(vector[0] == result);
    } catch (except(ELEMENT_NOT_EXIST)) {
        std::cout << "Element getting fault. Index is not in vector" << std::endl;
        cout_result(false);
    }

    try {
        std::cout << "vector[3] - " << vector[3] << std::endl;
        cout_result(false);
    } catch (except(ELEMENT_NOT_EXIST)) {
        std::cout << "Element getting fault. Index is not in vector" << std::endl;
        cout_result(true);
    }

    int result = 3;
    std::cout << "vector.get_length - " << vector.get_length() << std::endl;
    cout_result(vector.get_length() == result);
}
void test_setters()
{
    M_vector<int> vector{1, 2, 3};
    std::cout << "Setters test: " << std::endl << "Input data: " << vector << std::endl << "Expected results:" << std::endl << "vector.set_elem(0, 5) - [5, 2, 3]" << std::endl
         << "vector.set_elem(3, 5) - exception" << std::endl << std::endl;
    std::cout << "Results:" << std::endl;

    try {
        M_vector<int> result {5, 2, 3};
        vector.set_elem(0, 5);
        std::cout << "vector.set_elem(0, 5) - " << vector << std::endl;
        cout_result(vector == result);
    } catch (except(ELEMENT_NOT_EXIST)) {
        std::cout << "Element getting fault. Index is not in vector" << std::endl;
        cout_result(false);
    }

    try {
        vector.set_elem(3, 5);
        std::cout << "vector.get_elem(3, 5) - " << vector << std::endl;
        cout_result(false);
    } catch (except(ELEMENT_NOT_EXIST)) {
        std::cout << "Element getting fault. Index is not in vector" << std::endl;
        cout_result(true);
    }
}

void test_assignment()
{
    M_vector<int> a {1, 2}, b {1, 4, 8, 3};
    std::cout << "Assignment test: " << std::endl << "Input data: " << a << " = " << b  << std::endl << "Expected result: [1, 4, 8, 3]" << std::endl;
    a = b;
    std::cout << "Result: " << a << std::endl;
    M_vector<int> answer {1, 4, 8, 3};
    cout_result(a == answer);
}

void test_to_array()
{
    M_vector<int> vector {1, 5, 2};
    std::cout << "Сonversion to array test: " << std::endl << "Input data: " << vector << std::endl << "Expected results:" << std::endl << "vector.to_array()[0] = 1" << std::endl
         << "vector.to_array()[1] = 5" << std::endl << "vector.to_array()[2] = 2" << std::endl << std::endl;
    std::cout << "Results:" << std::endl;
    int result_0 = 1, result_1 = 5, result_2 = 2;
    std::cout << "vector.to_array()[0] = " << vector.to_array()[0] << std::endl << "vector.to_array()[1] = " << vector.to_array()[1] << std::endl
         << "vector.to_array()[2] = " << vector.to_array()[2] << std::endl << std::endl;
    cout_result(vector.to_array()[0] == result_0 && vector.to_array()[1] == result_1 && vector.to_array()[2] == result_2);
}

void test_glue()
{
    M_vector<int> a{1, 2, 3}, b{3, 4, 5};
    std::cout << "Concatenating test: " << std::endl << "Input data: " << a << " + " << b << std::endl << "Expected result: [1, 2, 3, 3, 4, 5]" << std::endl;
    std::cout << "Result: " << glue_vectors(a, b) << std::endl;
    M_vector<int> answer {1, 2, 3, 3, 4, 5};
    cout_result(glue_vectors(a, b) == answer);
}

void test_iterators()
{
    M_vector<int> vector{1, 2, 3};
    std::cout << "Iterators test: " << std::endl << "Input data: " << vector << std::endl << "Expected results:" << std::endl << "*vector.iterator_begin() = 1" << std::endl
         << "*vector.iterator_end() = 0" << std::endl << "vector.iterator_end().is_end() = 1" << std::endl << "*vector.iterator_begin().next() = 2" << std::endl;
    std::cout << "Result: " << "*vector.iterator_begin() = " << *vector.iterator_begin() << std::endl << "*vector.iterator_end() = " << *vector.iterator_end()
         << std::endl << "vector.iterator_end().is_end() = " << vector.iterator_end().is_end() << std::endl << "*vector.iterator_begin().next() = "
         << *vector.iterator_begin().next() << std::endl;
    int result_begin = 1, result_end = 0, result_next = 2;
    bool result_end_is_end = true;
    cout_result(*vector.iterator_begin() == result_begin && *vector.iterator_end() == result_end && vector.iterator_end().is_end() == result_end_is_end
                && *vector.iterator_begin().next() == result_next);
}
