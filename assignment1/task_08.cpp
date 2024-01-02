/*
"An image is represented by an m x n integer grid image where image[i][j]
represents the pixel value of the image.
You are also given three integers sr , sc and color . You should perform
a flood fill on the image starting from the pixel image[sr][sc] .
Return the modified image after performing the flood fill"
*/

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> solve(vector<vector<int>>&matrix,int row,int col,int src,int color);
/*
	 * @class name : Matrix
	 * @brief : TO save the values of the ro and col two make a 2D 
	 * @members:row and col are the row and columns of the matrix,vector is the 2D vector
	 */
class Matrx
{
    private:
        int row;
        int col;
        vector<vector<int>> matrix;
        
};
int main()
{
    int row, col, i = 0, j = 0,src=0,color=0,pos1=0,pos2=0;
    cout << "Enter the row of the matrx :";
    cin >> row;
    cout << "Enter the col of the matrx :";
    cin >> col;
    cout<<"Enter the position(i,j) of the matrix :";
    cin>>pos1>>pos2;
    cout << "Enter the source of the matrx :";
    cin >> src;
    cout << "Enter the color of the matrx :";
    cin >> color;
    vector<vector<int>> matrix(row, vector<int>(col));
    vector<vector<int>> matrix1(row, vector<int>(col));

    cout<<"Enter the    matrx "<<endl;
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

    matrix1=solve(matrix,pos1,pos2,src,color);

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

/*
	 * @func : Solve
	 * @brief : function descriptionIt is a reccursssive function that changes the source into color
     * @return:It returns the matrix that passed through referrence
	 */
vector<vector<int>> solve(vector<vector<int>>&matrix,int i,int j,int src,int color)
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

   return matrix;
   

}
