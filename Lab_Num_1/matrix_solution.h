//
// Created by Александр Желтиков on 03.10.2022.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cout;

#ifndef LAB_1_MATRIX_SOLUTION_H
#define LAB_1_MATRIX_SOLUTION_H



class Matrix{

private:

    vector<vector<float>> matrix;
    int column_count = 0;
    int row_count = 0;

public:

    Matrix(int row = 0 ,int column = 0);// Деструктор
    Matrix(vector<vector<float>> matr);

    void Transpose(); //+ Функция для транспонирования матрицы

    void OutPut();//+ Функция для вывода матрицы на экран

    void Sum(Matrix A,Matrix B); //+ Функция для суммирования матрицы

    void Difference(Matrix A,Matrix B); //+ Функция для вычитания матрицы

    void Triangular_view(); //+ Функция для приведения матрицы к треугольному виду

    void Multiplication(Matrix A, Matrix B);//+ Умножение матриц

    float GiveElem(int i, int j){
        return this->matrix[i][j];
    }

    vector<vector<float>> Out();
};




#endif //LAB_1_MATRIX_SOLUTION_H
