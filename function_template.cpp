#include<iostream>
#include<string>
using namespace std;
template<class T>
T sum(T x,T y)
{
    return x + y;
}
int main()
{

    cout<<sum<int>(1,2)<<endl;
    cout<<sum<float>(1.2f,2.2f)<<endl;
    cout<<sum<double>(1.4,2.8)<<endl;
    cout<<sum<string>("hello","world")<<endl;
    return 0;

}
