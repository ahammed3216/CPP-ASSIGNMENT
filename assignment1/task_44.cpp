#include<iostream>
#include<vector>
#include<memory>
using namespace std;
class UniqueList final
{
    private:
        int m ;
        int n;
    
    public:
        UniqueList()
        {
           
        }

        int path(int a , int b)
        {
            
                if(a==1 || b==1)
                {
                    return 1;
                }

                return path(a-1,b)+path(a,b-1);
            

        }


};
int main()
{
    unique_ptr<UniqueList>ptr=make_unique<UniqueList>();
    int result=ptr->path(3,8);
    cout<<"the unique path in the grid is "<<result;
}