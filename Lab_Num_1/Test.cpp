#include "Test.h"
#include "matrix_solution.h"


using namespace boost::numeric::ublas;

void inpTest(matrix<float> &x, Matrix y){
    for(int i = 0; i < x.size1();i++)
        for(int j = 0; j < x.size2(); j++)
            x(i,j) = y.GiveElem(i,j);
}

std::vector<std::vector<float>> outTets(matrix<float> x){
    std::vector<std::vector<float>> test;
    for(int i = 0; i < x.size1();i++){
        std::vector<float> temp;
        for(int j = 0; j < x.size2(); j++)
            temp.push_back(x(i,j));
        test.push_back(temp);
    }
    return test;
}

void TestTranspose (){
    {
        std::vector<std::vector<float>> test = {{1,1},{1,1}};
        std::vector<std::vector<float>> A_test;
        Matrix A(test);
        A.Transpose();
        A_test = A.Out();
        assert(A_test == test);
    }
    {

        std::vector<std::vector<float>> test = {{1,2,1},{1,1,3},{7,1,1}};
        std::vector<std::vector<float>> A_test;
        Matrix A(test);
        std::vector<std::vector<float>> correct = {{1,1,7},{2,1,1},{1,3,1}};
        A.Transpose();
        A_test = A.Out();
        assert(A_test == correct);
    }
    std::cout << "Test Transpose function OK!\n";
}

void TestSum (){
    {
        std::vector<std::vector<float>> _test1 = {{1,1},{1,1}};
        std::vector<std::vector<float>> _test2 = {{1,1},{2,2}};

        std::vector<std::vector<float>> CheckMatrix;
        std::vector<std::vector<float>> CheckBoost;

        Matrix A(_test1);
        Matrix B(_test2);
        Matrix C;

        matrix<float> _A(_test1.size(),_test1[0].size());
        matrix<float> _B(_test2.size(),_test2[0].size());
        matrix<float> _C;

        inpTest(_A, _test1);
        inpTest(_B, _test2);

        C.Sum(A,B);
        _C = _A + _B;

        CheckMatrix = C.Out();
        CheckBoost = outTets(_C);

        assert(CheckMatrix == CheckBoost);
    }
    {
        std::vector<std::vector<float>> _test1 = {{10,100},{1123,1231}};
        std::vector<std::vector<float>> _test2 = {{1123,111},{12,3322}};

        std::vector<std::vector<float>> CheckMatrix;
        std::vector<std::vector<float>> CheckBoost;

        Matrix A(_test1);
        Matrix B(_test2);
        Matrix C;

        matrix<float> _A(_test1.size(),_test1[0].size());
        matrix<float> _B(_test2.size(),_test2[0].size());
        matrix<float> _C;

        inpTest(_A, _test1);
        inpTest(_B, _test2);

        C.Sum(A,B);
        _C = _A + _B;

        CheckMatrix = C.Out();
        CheckBoost = outTets(_C);

        assert(CheckMatrix == CheckBoost);
    }
    std::cout << "Test Sum function OK!\n";
}

void TestDifference (){
    {
        std::vector<std::vector<float>> _test1 = {{1,1},{1,1}};
        std::vector<std::vector<float>> _test2 = {{1,1},{2,2}};

        std::vector<std::vector<float>> CheckMatrix;
        std::vector<std::vector<float>> CheckBoost;

        Matrix A(_test1);
        Matrix B(_test2);
        Matrix C;

        matrix<float> _A(_test1.size(),_test1[0].size());
        matrix<float> _B(_test2.size(),_test2[0].size());
        matrix<float> _C;

        inpTest(_A, _test1);
        inpTest(_B, _test2);

        C.Difference(A,B);
        _C = _A - _B;

        CheckMatrix = C.Out();
        CheckBoost = outTets(_C);

        assert(CheckMatrix == CheckBoost);
    }
    {
        std::vector<std::vector<float>> _test1 = {{10,100},{1123,1231}};
        std::vector<std::vector<float>> _test2 = {{1123,111},{12,3322}};

        std::vector<std::vector<float>> CheckMatrix;
        std::vector<std::vector<float>> CheckBoost;

        Matrix A(_test1);
        Matrix B(_test2);
        Matrix C;

        matrix<float> _A(_test1.size(),_test1[0].size());
        matrix<float> _B(_test2.size(),_test2[0].size());
        matrix<float> _C;

        inpTest(_A, _test1);
        inpTest(_B, _test2);

        C.Difference(A,B);
        _C = _A - _B;

        CheckMatrix = C.Out();
        CheckBoost = outTets(_C);

        assert(CheckMatrix == CheckBoost);
    }
    std::cout << "Test Difference function OK!\n";
}

void TestTriangular_view (){
    {
        std::vector<std::vector<float>> _test1 = {{1, 1, 1, 1},
                                                  {2, 3, 3, 3},
                                                  {2, 4, 5, 5},
                                                  {2, 5, 6, 7}};

        Matrix A(_test1);

        std::vector<std::vector<float>> CheckMatrix;

        std::vector<std::vector<float>> Check = {{1, 1, 1, 1},
                                                 {0, 1, 1, 1},
                                                 {0, 0, 1, 1},
                                                 {0, 0, 0, 1}};

        A.Triangular_view();

        CheckMatrix = A.Out();

        assert(CheckMatrix == Check);
    }

    std::cout << "Test Triangular View OK!\n";

}

void TestMultiplication(){
    {
        Matrix A(3, 3);
        Matrix B(3, 3);
        std::vector<std::vector<float>> _C;
        Matrix C;

        matrix<float> A_test(3, 3);
        matrix<float> B_test(3, 3);
        matrix<float> C_test(3, 3);
        inpTest(A_test, A);
        inpTest(B_test, B);
        std::vector<std::vector<float>> _C_test;

        C.Multiplication(A, B);
        C_test = prod(A_test, B_test);

        _C = C.Out();
        _C_test = outTets(C_test);

        assert(_C == _C_test);
    }

    std::cout << "Test Multiplication OK!\n";
}

void TestRunner(){
    std::cout << "Начало тестирования программы\n";
    TestTranspose();
    TestSum();
    TestDifference();
    TestMultiplication();
    TestTriangular_view();

    std::cout << "Тестирования программы завершено\n";
}