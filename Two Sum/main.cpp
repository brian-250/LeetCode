#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create hash table
        std::unordered_map<int, int> potential_values;

        // 'for loop' to find summation between two values in the given 'nums' array
        for (int index = 0; index < nums.size(); index++) {
            std::vector<int> pair;
            int missing_value = target - nums[index];
            int second_index = -1;
            // 'count member function' returns a boolean (1 or 0 is returned if the key is found or not respectively)
            second_index = potential_values.count(missing_value);
            
            // If key is found
            if (second_index == 1) {
                second_index = potential_values.at(missing_value);
                pair.push_back(index);
                pair.push_back(second_index);
                return pair;
            } 
            // If the key is not found in 'potential values'
            else {
                potential_values.insert({nums[index], index});
            }
        }
        // If nothing is returned from the for loop, return an empty array
        return {};
    }

int main() {
    std::vector<int> nums{2,7,11,15};
    int target = 9;
    std::vector<int> couple = twoSum(nums, target);
    for (auto c_index : couple) {
        std::cout << c_index << " ";
    }
    std::cout << std::endl;

    return 0;
}
