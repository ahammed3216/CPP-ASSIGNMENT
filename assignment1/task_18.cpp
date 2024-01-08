
#include <iostream>

#include <string>

#include <vector>

#include<algorithm>
 
int lengthOfLongestSubstring(const std::string &s)

{

    int n = s.length();

    int maxLength = 0, i = 0, j = 0;
 
    std::vector<char> charVector;
 
    while (j < n)

    {

        auto it = std::find(charVector.begin(), charVector.end(), s[j]);
 
        if (it == charVector.end())

        {

            charVector.push_back(s[j]);

            maxLength = std::max(maxLength, j - i + 1);

            j++;

        }

        else

        {

            charVector.erase(charVector.begin(), ++it);

            i++;

        }

    }
 
    for (auto &it : charVector)

    {

        std::cout << it << std::endl;

    }

    return maxLength;

}
 
int main()

{

    std::string input;

    std::cout << "Enter a string: ";

    std::cin >> input;
 
    int result = lengthOfLongestSubstring(input);
 
    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;
 
    return 0;

}
