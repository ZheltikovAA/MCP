using Microsoft.VisualStudio.TestPlatform.ObjectModel;

namespace UnitTest_Lab3;


public class Matrix
{
    private List<List<float>> matrix = new List<List<float>>();
    private int column_count = 0;
    private int row_count = 0;

    public Matrix(int row = 0, int column = 0)
    {
        row_count = row;
        column_count = column;
        for(int i = 0; i < row; i++)
        {

            List<float> temp = new List<float>();
            
            for(int j = 0; j < column; j++){
                temp.Add(0);
            }
            matrix.Add(temp);
        }
    }

    public Matrix(List<List<float>> x)
    {
        row_count = x.Count;
        column_count = x[0].Count();

        for(int i = 0; i < row_count;i++){
            matrix.Add(x[i]);
        }
    }
   public void OutPut() {

        for(int i = 0; i < row_count; i++){
            for(int j = 0; j < column_count; j++){
                Console.Write(matrix[i][j] + " ");
            }
            Console.WriteLine();
        }
    }
   
   public float GiveElem(int i, int j){
       return this.matrix[i][j];
   }
   
   public void Multiplication(Matrix A, Matrix B) {

       this.column_count = A.column_count;
       this.row_count = A.row_count;
       this.matrix.Clear();
       float foo = 0;
       for(int i = 0; i < A.row_count; i++){
           List<float> temp = new List<float>();
           for(int j = 0; j < A.column_count; j++){
               for(int k = 0; k < A.row_count; k++){
                   foo += A.matrix[i][k] * B.matrix[k][j];
               }
               temp.Add(foo);
               foo = 0;
           }
           this.matrix.Add(temp);
       }

   }
   
   public void Difference(Matrix A, Matrix B) {
       if (A.column_count == B.column_count && A.row_count == B.column_count){
           this.column_count = A.column_count;
           this.row_count = A.row_count;
           this.matrix.Clear();
           for(int i = 0; i < row_count;i++){
               List<float> temp = new List<float>();
               for(int j = 0; j < column_count; j++){
                   temp.Add(A.matrix[i][j] - B.matrix[i][j]);
               }
               this.matrix.Add(temp);
           }
       } else {
           Console.WriteLine("Error, matrix size are not equal!");
           
       }
   }
   
   public void Sum(Matrix A, Matrix B) {
       if (A.column_count == B.column_count && A.row_count == B.column_count){
           this.column_count = A.column_count;
           this.row_count = A.row_count;
           this.matrix.Clear();
           for(int i = 0; i < row_count;i++){
               List<float> temp = new List<float>();
               for(int j = 0; j < column_count; j++){
                   temp.Add(A.matrix[i][j] + B.matrix[i][j]);
               }
               this.matrix.Add(temp);
           }
       } else {
           Console.WriteLine("Error, matrix size are not equal!");
           
       }
   }
   
   public void Transpose(){
       float buff = 0;

       for(int i = 0; i < this.row_count; i++){

           for(int j = i; j < this.column_count; j++){

               buff = this.matrix[i][j];
               this.matrix[i][j] = this.matrix[j][i];
               this.matrix[j][i] = buff;

           }
       }
   }

   public List<List<float>> ToList()
   {
       List<List<float>> result = new List<List<float>>();

       for(int i = 0; i < this.row_count; i++)
       {
           List<float> temp = new List<float>();
           for(int j = 0; j < this.column_count; j++){
               temp.Add(this.matrix[i][j]);
           }
           result.Add(temp);
       }
       
       return result;
   }

}