#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<stack>
#include<sstream>
using namespace std;
class ReversePolish
{
    private:
        vector<string>expression;
        stack<int>subresult;
        float result;

    public:
        ReversePolish(vector<string>arr):expression(arr){}

        void evalExpress()
        {
            for(auto obj:expression)
            {
                stringstream ss(obj);
                int operand;
                int operant1=0,operant2=0;
                if(ss>>operand)
                {
                    subresult.push(operand);
                }
                else
                {
                    operant1=subresult.top();
                    subresult.pop();
                    operant2=subresult.top();
                    subresult.pop();
                    if(obj=="+")
                    {
                        subresult.push(operant2+operant1);

                    }
                    else if(obj=="-")
                    {
                        subresult.push(operant2-operant1);

                    }
                    else if(obj=="*")
                    {
                        subresult.push(operant1*operant2);
                    }
                    else
                    {
                        subresult.push(operant2/operant1);
                    }
                }
            }
            result=subresult.top();
        }

        void returnResult()
        {
            cout<<"\nThe value of the expression is "<<result;
            

        }
};
int main()
{
    vector<string>expression={"2","1","+","3","*"};
    vector<string>expression1={"4","13","5","/","+"};
    vector<string>expression2={"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    unique_ptr<ReversePolish>ptr=make_unique<ReversePolish>(expression2);
    ptr->evalExpress();
    ptr->returnResult();

}