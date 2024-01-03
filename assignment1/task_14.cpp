#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;
template<class T>
class LRUcache
{

private:
    
        unordered_map<int,pair<T,list<int>::iterator>> cache;
        list<int>LRU;
        int capacity;

public:
        LRUcache(int capacity)
        {
            cout<<"Constructor is called with value :"<<capacity<<endl;
                this->capacity=capacity;
        }
        void put(int key,T value)
        {
                if (cache.find(key) != cache.end())
                {
                    LRU.erase(cache[key].second);
                }
                else if(cache.size()>=capacity)
                {
                    int key_to_remove=LRU.back();
                    LRU.pop_back();
                    cache.erase(key_to_remove);
                }
                LRU.push_front(key);
                cache[key]= { value , LRU.begin()};
        }

        int get(int key)
        {
            if(cache.find(key) != cache.end())
            {
                int result_value=cache[key].first;
                LRU.erase(cache[key].second);
                LRU.push_front(result_value);
                cache[key].second=LRU.begin();
                return result_value;

            }
            else
            {
                return -1;
            }
        }

        void display()
        {
        
            for(list<int>::iterator i=LRU.begin();i!=LRU.end();i++)
            {
                
                cout<<(cache[*i].first)<<"\t";
            }
        }
};
int main()
{

    LRUcache<int> obj1(2);
   
    int result=0;

    cout<<"\n\n------Entering data into the tree--------\n\n";
    obj1.put(1,1);
    obj1.put(2,2);
     obj1.display();
    cout<<endl;

    obj1.put(3,7);  
    obj1.put(4,4);
     obj1.display();
    cout<<endl;

    obj1.put(5,5);
    obj1.put(6,6);
     obj1.display();
    cout<<endl;
    cout<<"\n\n-------------------------------------------\n\n";

    result=obj1.get(3);

    if(result==-1)
    {
        cout<<"the value is not found!!!";
    }
    else{
        cout<<"The value is looking for is "<<result;
    }

    



}
