#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // Create a vector with duplicate elements
    std::vector<int> numbers = {1, 2, 2, 3, 3, 4, 5, 5, 5, 6};

    // Use std::unique to remove consecutive duplicates
    auto last = std::unique(numbers.begin(), numbers.end());

    // Resize the vector to remove the elements after the unique ones
    numbers.erase(last, numbers.end());

    // Print the unique elements in the vector
    std::cout << "Unique elements in the vector: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
