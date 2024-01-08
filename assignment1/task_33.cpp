#include <iostream>
#include <vector>

class PermutationGenerator {
private:
    std::vector<int> nums;
    std::vector<std::vector<int>> result;

    void permuteHelper(int start) {
        if (start == nums.size() - 1) {
            result.push_back(nums);  // Add the permutation to the result when reaching the end
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            std::swap(nums[start], nums[i]);  // Swap the current element with subsequent elements
            permuteHelper(start + 1);  // Recursively generate permutations for remaining elements
            std::swap(nums[start], nums[i]);  // Backtrack: restore the original order of the elements
        }
    }

public:
    PermutationGenerator(const std::vector<int>& input) : nums(input) {}

    std::vector<std::vector<int>> generatePermutations() {
        permuteHelper(0);
        return result;
    }
};

int main() {
    std::vector<int> arr = {1, 2, 3};
    PermutationGenerator generator(arr);
    std::vector<std::vector<int>> res = generator.generatePermutations();

    // Print the permutations
    for (const auto& permutation : res) {
        for (const auto& num : permutation) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
