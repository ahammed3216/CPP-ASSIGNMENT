#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> solve(vector<vector<int>>matrix,int row,int col,int src,int color);
class Matrx
{
    private:
        int row;
        int col;
        vector<vector<int>> matrix;
        
};
int main()
{
    int row, col, i = 0, j = 0;
    cout << "Enter the row of the matrx :";
    cin >> row;
    cout << "Enter the col of the matrx :";
    cin >> col;
    vector<vector<int>> matrix(row, vector<int>(col));
    vector<vector<int>> matrix1(row, vector<int>(col));

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Printing the matrix :\n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << matrix[i][j]<<"\t";
        }
        cout<<endl;
    }

    //cout<<"check"<<matrix[0].size();

    matrix1=solve(matrix,1,1,1,2);

     cout << "Printing the matrix after the sort:\n";
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << matrix1[i][j]<<"\t";
        }
        cout<<endl;
    }

    

    return 0;
}

vector<vector<int>> solve(vector<vector<int>>matrix,int i,int j,int src,int color)
{
   
   if(i<0 || j<0 || i>=matrix.size() ||j>=matrix[0].size() || matrix[i][j] != src )
   {
        return matrix;
   }

   matrix[i][j]=color;
  
   solve(matrix,i,j+1,src,color);
   solve(matrix,i,j-1,src,color);
   solve(matrix,i+1,j,src,color);
   solve(matrix,i-1,j,src,color);
   cout<<endl;cout<<endl;
 for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;cout<<endl;
   
   

}
