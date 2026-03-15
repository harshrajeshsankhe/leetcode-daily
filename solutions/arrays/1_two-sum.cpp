```cpp
/*
Problem: Two Sum
Problem Number: 1
Difficulty: Easy
Topic: arrays
Date: 2026-03-15

Approach:
Use a hash map from value to its index while scanning the array once. For each number x, check if (target - x) already exists in the map; if so, we have found the required pair and return their indices. Otherwise, store x with its index and continue. This achieves a one-pass solution with constant average-time lookups.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> pos; // value -> index
        pos.reserve(nums.size() * 2);
        pos.max_load_factor(0.7f);

        for (int i = 0; i < (int)nums.size(); ++i) {
            int need = target - nums[i];
            auto it = pos.find(need);
            if (it != pos.end()) {
                return {it->second, i};
            }
            // Store after checking to avoid using the same element twice.
            pos[nums[i]] = i;
        }
        return {}; // As per problem constraints, this line is unreachable.
    }
};
```