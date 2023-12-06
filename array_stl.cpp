#include<iostream>
#include<array>
#include<iterator>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    array<int,3> arr={8,2,3};
    array<int,3> arr1={'a','b','c'};
    cout<<endl<<"size of the array :"<<arr.size();
    cout<<endl<<"max size :"<<arr.max_size();
    cout<<endl<<"start :"<<arr.front();
    cout<<endl<<"end :"<<arr.back();

    sort(arr.begin(),arr.end());

    for(auto i=0;i<arr.size();i++)
    {

        cout<<endl<<arr[i];
    }

    arr.fill(9);
    cout<<"Filling the array";
     for(auto i=0;i<arr.size();i++)
    {

        cout<<endl<<arr[i];
    }
    cout<<"swaping the array values :";

    arr.swap(arr1);
   for(auto i=0;i<arr.size();i++)
    {

        cout<<endl<<arr[i];
    }





}



//udemy code


/*

    
/*
Define Array:-
Arrays are fixed-size sequence containers
Therefore, they cannot be expanded or contracted dynamically*/

/*
properties:-
1. Sequence:- Elements in container follow strict linear sequence.
			  Individual elements are accessed by their position 
			  in this sequence.

2. Contiguous storage:- The elements are stored in contiguous memory
						locations.

3. Fixed-size aggregate:- The container uses implicit constructors 
						and destructors to allocate the required space.
						i) Explicitly Constructor call
						test obj = test(10);

						ii) Implicitly Constructor call
						test obj(10);


#include<iostream>
#include<array>   // Include the array header
using namespace std;

int main()
{
//array declaration
	std::array<int, 3> testArray1;

//array intialization
	std::array<int, 3> testArray2 = { 10,20,30 };

//methods
	cout << "At " << testArray2.at(2) << endl;		//out of bound safe

	cout << "[] " << testArray2[2] << endl;			//unsafe

	cout << "front() " << testArray2.front() << endl;  //  return 1st element

	cout << "back() " << testArray2.back() << endl;  // return last element 

	testArray1.fill(0);							  // fill array with 0

	testArray1.swap(testArray2);					// swap arrays

	testArray1.empty();  							// empty the array

	cout << "size() " << testArray2.size() << endl;  // size of array filled

	cout << "max_size() " << testArray2.max_size() << endl; // max size of array

	return 0;
}


*/