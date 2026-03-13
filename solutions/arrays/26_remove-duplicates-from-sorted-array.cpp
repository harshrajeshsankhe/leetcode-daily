```cpp
/*
Problem: Remove Duplicates from Sorted Array
Problem Number: 26
Difficulty: Easy
Topic: arrays
Date: 2026-03-13

Approach:
Since the array is sorted, duplicates appear in consecutive positions. Use two pointers: a write index k for the next unique position, and a read index i that scans the array. Whenever nums[i] differs from the last written unique value nums[k-1], write it to nums[k] and increment k. Return k as the count of unique elements.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        if (n == 0) return 0;

        int k = 1; // nums[0] is always unique
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[k - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
```