#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
class Account final
{
    private:
        vector<vector<string>>accounts;
        vector<vector<string>>result;
        //unordered_set<vector<string>>result1;
        vector<string>visited;
    public:
        Account(vector<vector<string>>arr):accounts(arr){}

        void MergeAccount()
        {
            
            for(auto mail :accounts)
            {
                unordered_set<string>check(mail.begin(),mail.end());
                string name=mail[0];
                vector<string>row;
               
                    for(auto mail1:accounts)
                    {
                        string name1=mail1[0];
                        
                        int flag=-1;
                        if(name==name1)
                        {
                            for(auto obj:mail1)
                            {
                                if(check.find(obj)!=check.end())
                                {
                                    flag++;
                                }
                            }
                        }
                        if(flag>=1)
                        {
                            for(auto obj:mail1)
                            {
                                check.insert(obj);
                            }              
                            
                        }
                        
                    }
                    for(auto obj1:check)
                    {
                        row.push_back(obj1);
                    }
                    sort(row.begin(),row.end());
                    if(find(result.begin(),result.end(),row)==result.end())
                        result.push_back(row);
                    row.clear();
                    check.clear();
                    cout<<endl;

               
            }
        }

};
int main()
{
    vector<vector<string>>accounts={{"John","johnsmith@mail.com","john_newyork@mail.com"},
    {"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};

    vector<vector<string>>accounts1 = {{"Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"},{"Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"},{"Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"},{"Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"},{"Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"}};

    unique_ptr<Account>ptr=make_unique<Account>(accounts1);

    ptr->MergeAccount();
}