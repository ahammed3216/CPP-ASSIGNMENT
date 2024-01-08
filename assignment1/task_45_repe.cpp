#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<map>
using namespace std;
template<class T>
class Integer
{
    private:
        vector<T> nums;
        map<T,int>count;
    
    public:
        Integer(vector<T> arr):nums(arr){}

        void repetion()
        {
            vector<T>copy;
            bool flag;

            for(auto i=nums.begin();i!=nums.end();i++)
            {
                auto it=find(copy.begin(),copy.end(),*i);
                if(it == copy.end())
                {
                    copy.push_back(*i);
                    count[*i]=1;
                }
                else
                {
                    count[*i]++;
                    
                }
            }


        }

        void display_cout()
        {
           
            for(const auto obj :count)
            {
                cout<<obj.first<<" repeated for "<<"\t"<<obj.second<<" times"<<endl;
            }
        }
        
};
int main()
{
    vector<int>arr={1,4,3,4};
    unique_ptr<Integer<int>>ptr=make_unique<Integer<int>>(arr);
    ptr->repetion();

    ptr->display_cout();
}