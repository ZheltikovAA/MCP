
#include "matrix_solution.h"


// Деструктор, который задает матрицу из случайных чисел.
Matrix::Matrix(int row, int column) {
    row_count = row;
    column_count = column;
    srand(rand() % 100);
    for(size_t i = 0; i < row; i++){

        std::vector<float> temp;

        for(size_t j = 0; j < column; j++){
            temp.push_back(rand() % 50);
        }

        matrix.push_back(temp);
    }
}

void Matrix::Transpose() {
    float buff = 0;

    for(int i = 0; i < this->row_count; i++){

        for(int j = i; j < this->column_count; j++){

            buff = this->matrix[i][j];
            this->matrix[i][j] = this->matrix[j][i];
            this->matrix[j][i] = buff;

        }
    }
}

void Matrix::Sum(Matrix A, Matrix B) {
    if (A.column_count == B.column_count && A.row_count == B.column_count){

        this->column_count = A.column_count;
        this->row_count = A.row_count;
        this->matrix.clear();

        for(int i = 0; i < row_count;i++){
            std::vector<float> temp;
            for(int j = 0; j < column_count; j++){
                 temp.push_back(A.matrix[i][j] + B.matrix[i][j]);
            }
            this->matrix.push_back(temp);
        }
    } else {
        std::cout << "Error, matrix size are not equal!";
    }
}

void Matrix::OutPut() {

    for(size_t i = 0; i < row_count; i++){
        for(size_t j = 0; j < column_count; j++){
        std::cout<< matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void Matrix::Difference(Matrix A, Matrix B) {
    if (A.column_count == B.column_count && A.row_count == B.column_count){
        this->column_count = A.column_count;
        this->row_count = A.row_count;
        this->matrix.clear();
        for(int i = 0; i < row_count;i++){
            std::vector<float> temp;
            for(int j = 0; j < column_count; j++){
                temp.push_back(A.matrix[i][j] - B.matrix[i][j]);
            }
            this->matrix.push_back(temp);
        }
    } else {
        std::cout << "Error, matrix size are not equal!";
    }
}

void Matrix::Triangular_view() {
    float define;
    int step = 0;

    while (step < this->column_count){

        for(int i = step+1; i < this->row_count; i++){
            if(this->matrix[step][step] != 0)
                define = this->matrix[i][step] / this->matrix[step][step];
            else define = 0;
            for (int j = 0; j < this->column_count; j++){

                this->matrix[i][j] = this->matrix[i][j] - ( define * this->matrix[step][j] );
                if (abs(this->matrix[i][j]) < 1e-5) this->matrix[i][j] = 0;
            }
        }
    step++;
    }
}

void Matrix::Multiplication(Matrix A, Matrix B) {

    this->column_count = A.column_count;
    this->row_count = A.row_count;
    this->matrix.clear();
    float foo = 0;
    for(int i = 0; i < A.row_count; i++){
        std::vector<float> temp;
        for(int j = 0; j < A.column_count; j++){
            for(int k = 0; k < A.row_count; k++){
                foo += A.matrix[i][k] * B.matrix[k][j];
            }
            temp.push_back(foo);
            foo = 0;
        }
        this->matrix.push_back(temp);
    }

}

Matrix::Matrix(vector<vector<float>> matr) {
    row_count = matr.size();
    column_count = matr[0].size();

    for(int i = 0; i < row_count;i++){
        matrix.push_back(matr[i]);
    }
}

vector<vector<float>> Matrix::Out() {
    std::vector<std::vector<float>> answer;
    for(size_t i = 0; i < row_count; i++){
        std::vector<float> temp;
        for(size_t j = 0; j < column_count; j++){
            temp.push_back(matrix[i][j]);
        }
        answer.push_back(temp);

    }
    return answer;
}
