	#include<iostream>
	#include<string>
	using namespace std;
	int main()
	{
	string inputStr,string1;
	cout<<"Enter the string"<<endl;
	getline(cin,inputStr);
	int i=0,length=0,j=0;
	
	length=inputStr.length();
	cout<<"the length of the string is"<<length<<endl;
	
	for(j=0,i=length-1;i>=0;i--,j++)
	{
	    
	  
	    string1+=inputStr[i];
	   
	    
	}
	cout<<"check";
	cout<<string1;
	}