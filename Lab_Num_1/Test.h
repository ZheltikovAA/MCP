

#ifndef LAB_1_TEST_H
#define LAB_1_TEST_H

/*
 *          Чек лист проверок:
 *
 *          5 Тестов для каждой функции,
 *          также тесты будут приложены в pdf файле с документацией тестсистеме
 *
 *
 *
 * */
#include <iostream>
#include <cassert>
#include <vector>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

void TestTranspose ();

void TestSum ();

void TestDifference ();

void TestTriangular_view ();

void TestMultiplication();

void TestRunner();


#endif //LAB_1_TEST_H
