```cpp
/*
Problem: Find All Numbers Disappeared in an Array
Problem Number: 448
Difficulty: Easy
Topic: arrays
Date: 2026-03-25

Approach:
Use the array itself to mark which values in [1..n] are present by flipping the sign at index (value-1) to negative.
After marking, any index i that still holds a positive number indicates that (i+1) never appeared in the array.
This achieves O(1) extra space (excluding the output) by reusing the input array as a visitation bitmap.

Time Complexity: O(n)
Space Complexity: O(1) extra (excluding output)
*/

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        const int n = (int)nums.size();

        // Mark presence: for each value v, mark nums[v-1] as negative.
        for (int i = 0; i < n; ++i) {
            int v = std::abs(nums[i]);        // value in [1..n]
            int idx = v - 1;                  // target index in [0..n-1]
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }

        // Collect indices not marked (still positive) => missing numbers.
        std::vector<int> missing;
        missing.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) missing.push_back(i + 1);
        }
        return missing;
    }
};
```