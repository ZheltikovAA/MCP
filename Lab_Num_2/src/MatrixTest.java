import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

public class MatrixTest {

    private float[][] x;
    private float[][] y;

    private Matrix A;
    private Matrix B;
    private Matrix C;

    @Before
    public void setUp() throws Exception{

        x = new float[][]{{4, 1, 1}, {1, 1, 8}, {15, 1, 1}};
        y = new float[][]{{1, 2, 1}, {2, 1, 1}, {2, 1, 1}};
        B = new Matrix(y);
        A = new Matrix(x);
        C = new Matrix(0,0);

    }


    @Test
    public void TestTranspose() {

        A.Transpose();
        float[][] tr = {{4,1,15},{1,1,1},{1,8,1}};
        float[][] _test = A.Vector();
        assertEquals(_test,tr);
    }

    @Test
    public void TestSum() {

        C.Sum(A,B);

        float c[][] = {{5,3,2},{3,2,9},{17,2,2}};
        float[][] _test = C.Vector();
        Assert.assertEquals(c,_test);
    }

    @Test
    public void TestDifference(){
        C.Difference(A,B);

        float c[][] = {{3,-1,0},{-1,0,7},{13,0,0}};
        float[][] _test = C.Vector();
        Assert.assertEquals(c,_test);
    }

    @Test
    public void TestMultiplication() {
        C.Multiplication(A,B);
        float c[][] = {{8,10,6},{19,11,10},{19,32,17}};
        float[][] _test = C.Vector();

        Assert.assertEquals(c,_test);
    }

    @Test
    public void TestMatrixToList(){

        float[][] _test = A.Vector();

        Assert.assertEquals(x,_test);
    }
}