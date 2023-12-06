#include<iostream>
#include<iterator>
#include<list>
using namespace std;
int main()
{

    list<int> list1={20,30,40};
    for(list<int>::iterator i=list1.begin();i!=list1.end();i++)
    {

        cout<<*i<<"\t";
    }

    list1.push_back(50);//insert in the back 

    list1.push_front(100);// insert in thr top side

    list1.pop_back();

    list1.pop_front();

    list<int>::iterator j=list1.begin();
    list1.insert(j,70);


    cout<<endl;
      for(list<int>::iterator i=list1.begin();i!=list1.end();i++)
    {

        cout<<*i<<"\t";
    }


list1.sort();

list1.reverse();



}


/*

#include<iostream>
#include<list>   // Include the list header
using namespace std;

int main()
{
	//declaration
	std::list<int> list1;

	//intialization        100,200,300   
	std::list<int> list2 = { 1,2,3};

	//methods
	list<int>::iterator i = list2.end();

	//insert
	list2.insert(i, 10);

	for (list<int>::iterator i = list2.begin(); i != list2.end(); i++)
	{
		cout << *i << " ";   // for printing the list
	}

	//push_back     1,2,3,20
	list2.push_back(20);

	//push_front    10,1,2,3,20
	list2.push_front(10);

	//pop_back      10,1,2,3
	list2.pop_back();

	//pop_front    1,2,3
	list2.pop_front();

	//reverse      3,2,1
	list2.reverse();

	//swap
	list2.swap(list1);

	//size :- no of element present in list  = 3
	list1.size();

	//sort    1,2,3
	list1.sort();

	//merge   10,20,1,2,3
	list1.merge(list2);

	return 0;
}
*/