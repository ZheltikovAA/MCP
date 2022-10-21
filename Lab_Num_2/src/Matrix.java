public class Matrix {


    private int row_count = 0;
    private int column_count = 0;
    private float matrix[][] = new float[row_count][column_count];

    Matrix(int row , int column ){
        row_count = row;
        column_count = column;

        matrix = new float[row][column];

        for (int i = 0; i < row; i++){
            for (int j = 0; j < column; j++){
                matrix[i][j] = 0;
            }
        }
    }

    Matrix(float[][] M){
        row_count = M.length;
        column_count = M[0].length;

        matrix = new float[row_count][column_count];

        for (int i = 0; i < row_count; i++){
            System.arraycopy(M[i], 0, matrix[i], 0, column_count);
        }
    }

    void Transpose(){
        float buff = 0;

        for(int i = 0; i < this.row_count; i++){
            for(int j = i; j < this.column_count; j++){

                buff = this.matrix[i][j];
                this.matrix[i][j] = this.matrix[j][i];
                this.matrix[j][i] = buff;

            }
        }
    }

    void Sum(Matrix A, Matrix B){
        if (A.column_count == B.column_count && A.row_count == B.column_count){

            this.row_count = A.row_count;
            this.column_count = A.column_count;
            this.matrix = A.matrix;

            for(int i = 0; i < row_count;i++){
                for(int j = 0; j < column_count; j++){
                    this.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
                }
            }
        } else {
            System.out.println("Error, matrix size are not equal!");
        }
    }


    void Difference(Matrix A, Matrix B){
        if (A.column_count == B.column_count && A.row_count == B.column_count){

            this.row_count = A.row_count;
            this.column_count = A.column_count;
            this.matrix = A.matrix;

            for(int i = 0; i < row_count;i++){
                for(int j = 0; j < column_count; j++){
                    this.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
                }
            }
        } else {
            System.out.println("Error, matrix size are not equal!");
        }
    }

    void outPut(){
        for(int i = 0; i < row_count;i++){
            for(int j = 0; j < column_count; j++){
                System.out.print(this.matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    void Multiplication(Matrix A, Matrix B) {

        this.row_count = A.row_count;
        this.column_count = A.column_count;
        Matrix C = new Matrix(this.row_count,this.column_count);
        float foo = 0;
        for(int i = 0; i < A.row_count; i++){
            for(int j = 0; j < A.column_count; j++){
                foo = 0;
                for(int k = 0; k < A.row_count; k++){
                    foo += A.matrix[i][k] * B.matrix[k][j];
                }
                C.matrix[i][j] = foo;
            }
        }
        this.matrix = C.matrix;
    }

    float[][] Vector(){
        float[][] result = new float[this.row_count][this.column_count];

        for(int i = 0; i < this.row_count;i++){
            if (this.column_count >= 0) System.arraycopy(this.matrix[i], 0, result[i], 0, this.column_count);
        }

        return result;
    }
}
