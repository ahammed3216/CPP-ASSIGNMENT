/*5. Write a C++ program to replace a word from the string */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string var1 = "", var2 = "", var3 = "";

    cout << endl << "enter string :";
    getline(cin, var1);

    cout << endl << "enter string to find:";
    getline(cin, var2);

    cout << endl << "enter string to replace:";
    getline(cin, var3);


    while (var1.find(var2) != string::npos)
        var1.replace(var1.find(var2), var2.size(), var3);

    cout << var1;
    
    return 0;
}