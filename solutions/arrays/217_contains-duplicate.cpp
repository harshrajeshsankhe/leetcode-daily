```cpp
/*
Problem: Contains Duplicate
Problem Number: 217
Difficulty: Easy
Topic: arrays
Date: 2026-03-15

Approach:
Use an unordered_set to track values seen so far while scanning the array once.
If a value is already present in the set, a duplicate exists and we return true immediately.
Otherwise insert it and continue; if we finish, all elements are unique.

Time Complexity: O(n) average
Space Complexity: O(n)
*/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        seen.reserve(nums.size() * 2);              // reduce rehashing
        seen.max_load_factor(0.7f);

        for (int x : nums) {
            if (seen.find(x) != seen.end()) return true;
            seen.insert(x);
        }
        return false;
    }
};
```