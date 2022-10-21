namespace UnitTest_Lab3;
using System.Collections.Generic;


public class Tests
{
    
    private List<List<float>> _x;
    private List<List<float>> _y;
    private Matrix A;
    private Matrix B;
    private Matrix C;
    private List<List<float>> _test;
    private List<List<float>> _chekc;
    

    [SetUp]
    public void Setup()
    {
        _x = new List<List<float>>()
        {
            new List<float>() {1,2,3},
            new List<float>() {1,2,3},
            new List<float>() {1,2,3},
        };

        _y = new List<List<float>>()
        {
            new List<float>() {3,2,-8},
            new List<float>() {1,4,3},
            new List<float>() {0,2,3},
        };

        _test = new List<List<float>>();
        _chekc = new List<List<float>>();
        
        
       A = new Matrix(_x);
       B = new Matrix(_y);
       C = new Matrix(3,3);
    }
    
    [Test]
    public void TestSum()
    {
        _chekc = new List<List<float>>()
        {
            new List<float>() {4,4,-5},
            new List<float>() {2,6,6},
            new List<float>() {1,4,6},
        };
        
        C.Sum(A,B);
        _test = C.ToList();

        Assert.AreEqual(_test, _chekc);
    }
    
    [Test]
    public void TestTranspose()
    {
        _chekc = new List<List<float>>()
        {
            new List<float>() {1,1,1},
            new List<float>() {2,2,2},
            new List<float>() {3,3,3},
        };
        
        A.Transpose();
        _test = A.ToList();

        Assert.AreEqual(_test, _chekc);
    }
    
    
    [Test]
    public void TestDifference()
    {
        _chekc = new List<List<float>>()
        {
            new List<float>() {-2,0,11},
            new List<float>() {0,-2,0},
            new List<float>() {1,0,0},
        };
        
        C.Difference(A,B);
        _test = C.ToList();

        Assert.AreEqual(_test, _chekc);
    }
    
    [Test]
    public void TestMultiplication()
    {
        _chekc = new List<List<float>>()
        {
            new List<float>() {5,16,7},
            new List<float>() {5,16,7},
            new List<float>() {5,16,7},
        };
        
        C.Multiplication(A,B);
        _test = C.ToList();

        Assert.AreEqual(_test, _chekc);
        
            // Заведомо ложный тест 
            
                 
        _chekc = new List<List<float>>()
        {
            new List<float>() {4,16,7}, // Здесь ошибка.
            new List<float>() {5,16,7},
            new List<float>() {5,16,7},
        };
        
        Assert.AreEqual(_test, _chekc);
    }
    
}