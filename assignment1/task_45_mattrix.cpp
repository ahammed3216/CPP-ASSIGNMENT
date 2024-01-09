#include<iostream>
#include<vector>
#include<memory>
using namespace std;
template<class T>
class Matrix
{
    private:
        vector<vector<T>>matrix1;
        vector<vector<T>>matrix2;
        vector<vector<T>>result_matrix;

    public:
        void AddValues()
        {
            int row1,row2,col1,col2;
            cout<<"Enter the row of matrix 1 :";
            cin>>row1;
            cout<<"Enter the col of matrix 1 :";
            cin>>col1;
            cout<<"Enter the row of matrix 2 :";
            cin>>row2;
            cout<<"Enter the col of matrix 2 :";
            cin>>col2;

            cout<<"Enter the values of the matrix1 :";
            for(auto i=0;i<row1;i++)
            {
                vector<T>row;
                for(auto j=0;j<col1;j++)
                {
                    int temp=0;
                    cin>>temp;
                    row.push_back(temp);
                }
                matrix1.push_back(row);
                row.clear();
            }
            
             cout<<"Enter the values of the matrix2 :";
            for(auto i=0;i<row2;i++)
            {
                vector<T>row;
                for(auto j=0;j<col2;j++)
                {
                    int temp=0;
                    cin>>temp;
                    row.push_back(temp);
                }
                matrix2.push_back(row);
                row.clear();
            }
        }

        void display_matrix(int flag)
        {
            if(flag !=1)
            {
                cout<<"Printing the values of the matrix1 :\n";
                for(const auto obj:matrix1)
                {
                    for(auto it=obj.begin();it!=obj.end();it++)
                    {
                        cout<<*it<<"\t";
                    }
                    cout<<endl;
                }

                cout<<"Printing the values of the matrix2 :\n";
                for(const auto obj:matrix2)
                {
                    for(auto it=obj.begin();it!=obj.end();it++)
                    {
                        cout<<*it<<"\t";
                    }
                    cout<<endl;
                }
            }
            else
            {
                cout<<"Printing the values of the matrix multiplication :\n";
                for(const auto obj:result_matrix)
                {
                    for(auto it=obj.begin();it!=obj.end();it++)
                    {
                        cout<<*it<<"\t";
                    }
                    cout<<endl;
                }

            }
        }

        bool check_mul()
        {
            int row1,col1,row2,col2;
            row1=matrix1.size();
            row2=matrix2.size();
            col1=matrix1[0].size();
            col2=matrix2[0].size();

            if(row1==col2 && col1==row2)
            {
                return true;
            }
            else
            {
                return false;
            }

        }

        void matrix_mul()
        {
            int row1,col1,row2,col2;
            row1=matrix1.size();
            row2=matrix2.size();
            col1=matrix1[0].size();
            col2=matrix2[0].size();

            for(auto i=0;i<row1;i++)
            {
                vector<T>subres;
                
                for(auto j=0;j<col2;j++)
                {
                    T result=0;
                    for(auto k=0;k<col1;k++)
                    {
                        result+=matrix1[i][k]*matrix2[k][j];
                    }
                    subres.push_back(result);
                }
                result_matrix.push_back(subres);
                subres.clear();
            }

            this->display_matrix(1);


        }
    
};
int main()
{
    unique_ptr<Matrix<int>>ptr=make_unique<Matrix<int>>();
    ptr->AddValues();
    ptr->display_matrix(0);
    bool check=ptr->check_mul();

    if(check==true)
    {
        cout<<"The multiplication is possible ";
        ptr->matrix_mul();

    }
    else
    {
        cout<<"The multiplication is not possible ";
    }
}