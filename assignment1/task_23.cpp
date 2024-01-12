/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1 . 
You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates 
that you must take course bi first if you want to take course ai . 
Return true if you can finish all courses. Otherwise, return false .
*/

#include<iostream>
#include<memory>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Course final
{
    private:
        vector<vector<int>>course;
        vector<int>visted;
        unordered_map<int,vector<int>>pre;


    public:
        Course(vector<vector<int>>arr):course(arr){}

        void CheckCourse()
        {
            for(auto obj:course)
            {
                pre[obj[0]].push_back(obj[1]);
                //visted.push_back(obj[0]);
            }
            bool result=PreCheck(0);
            if(result==true)
            {
                cout<<"sucess";
            }
            else
            {
                cout<<"failed";
            }
        }

        bool PreCheck(int course)
        {

           if(pre.find(course)==pre.end())
            {
                return true;
            }

            if(find(visted.begin(),visted.end(),course)==visted.end())
            { 
                    visted.push_back(course);
            }
            else
            {
                return false;
            }
              
            
              
            for(auto demo:pre[course])
            {
                bool result=PreCheck(demo);
                if(result)
                {
                    auto it=find(pre[course].begin(),pre[course].end(),demo);
                    if(it!=pre[course].end())
                    {
                        pre[course].erase(it);
                        
                    }

                }
                else
                {
                    return false;
                }
            }
            return true;
        }

};
int main()
{
    vector<vector<int>>arr={{0,1},{0,2},{1,3},{1,4},{3,4}};
    vector<vector<int>>arr1={{0,1},{1,0}};
    vector<vector<int>>arr2={{0,1},{1,2},{2,0}};
    vector<vector<int>>arr3={{0,1}};
    unique_ptr<Course>ptr=make_unique<Course>(arr3);
    ptr->CheckCourse();
    

}