#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main()
{

        vector<int>array1={1,5,3};
        vector<int>array2={'a','b'};
        cout<<"capacity :"<<array1.capacity();

        cout<<endl<<"at first positon"<<array1.at(1)<<endl;
        
        array1.push_back(30);
        
        for(vector<int>::iterator i=array1.begin();i!=array1.end();i++)
        {


            cout<<*i<<endl;
        }

        array1.pop_back();
    

     for(vector<int>::iterator i=array1.begin();i!=array1.end();i++)
        {


            cout<<*i<<"\t";
        }
        
        cout<<endl<<"capacity :"<<array1.capacity()<<endl;
        
        //cout<<"data:"<<array1.data();
        


        vector<int>::iterator i=array1.begin();        
        array1.insert(i,90);
          for(vector<int>::iterator i=array1.begin();i!=array1.end();i++)
        {


            cout<<*i<<"\t";
        }
    cout<<endl;
        vector<int>::iterator j=array1.begin(); 
        array1.erase(i);
            for(vector<int>::iterator i=array1.begin();i!=array1.end();i++)
        {


            cout<<*i<<"\t";
        }

        array1.swap(array2);
        cout<<endl;
        cout<<"swapping\n";
            for(vector<int>::iterator i=array1.begin();i!=array1.end();i++)
        {


            cout<<*i<<"\t";
        }
        
}



/*

#include<iostream>
#include<vector>   // Include the vector header
using namespace std;

int main()
{
	//declaration
	std::vector<int> testVector1;

	cout << "Size " << testVector1.size() << endl;

	//intialization
	std::vector<int> testVector2 = { 10,20,30};
	                               //0,1,2            
	//methods
	cout << "At " << testVector2.at(2) << endl;		//out of bound safe

	cout << "[] " << testVector2[2] << endl;			//unsafe

	testVector2.push_back(40); //inserting an element at the end of the vector
	testVector2.push_back(50);
	testVector2.push_back(60);

	//iterator is pointer to container     10,20,30,40,50,60
										//	i

	for (vector<int>::iterator i = testVector2.begin(); i != testVector2.end(); i++)
	{
		cout << *i << " ";   // for printing the vector
	}

	cout << endl;

	//pop out last element
	testVector2.pop_back();

	//now lets check
	for (vector<int>::iterator i = testVector2.begin(); i != testVector2.end(); i++)
	{
		cout << *i << " ";   // for printing the vector
	}


	//insert:- inserts the element in vector before the position pointed
	//by iterator           10,20,30,40,50
	vector<int>::iterator i = testVector2.begin();
	testVector2.insert(i, 0);

	//erase:- removes the element pointed by the iterator.
	//vector<int>::iterator i = testVector2.begin();
	//testVector2.erase(i);

	//erase all element except last element
	testVector2.erase(testVector2.begin(), testVector2.end() - 1);

	//swap: interchanges value of two vectors
	testVector2.swap(testVector1);

	//capacity :number of elements that can be inserted 
	//in the vector based on the memory allocated to the vector
	cout << endl << "Capacity " << testVector2.capacity() << endl;
	return 0;
}



*/