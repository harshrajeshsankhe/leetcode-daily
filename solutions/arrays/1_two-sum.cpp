```cpp
/*
Problem: Two Sum
Problem Number: 1
Difficulty: Easy
Topic: arrays
Date: 2026-03-13

Approach:
Scan the array once while storing each seen value and its index in a hash map.
For each number x, check whether (target - x) already exists in the map; if it does, we found the pair.
This yields the first valid pair in linear time by leveraging O(1) average-time lookups.

Time Complexity: O(n) average (O(n^2) worst-case with pathological hashing)
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
            // Store current value after checking to avoid using the same element twice.
            pos[nums[i]] = i;
        }
        return {}; // Per problem statement, a solution always exists.
    }
};
```