public class Main {


    public static void main(String[] args) {

        float[][] x = {{4,1,1},{1,1,8},{15,1,1}};
        Matrix A = new Matrix(x);

        A.Transpose();
        float[][] tr = {{4,1,15},{1,1,1},{1,8,1}};
        Matrix C = new Matrix(tr);
        A.outPut();

        C.outPut();
    }


}