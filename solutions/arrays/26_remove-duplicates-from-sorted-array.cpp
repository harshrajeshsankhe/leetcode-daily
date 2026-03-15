```cpp
/*
Problem: Remove Duplicates from Sorted Array
Problem Number: 26
Difficulty: Easy
Topic: arrays
Date: 2026-03-15

Approach:
Use two pointers: a write index that tracks the position to place the next unique value, and a read index that scans the array.
Because the array is sorted, duplicates are adjacent; whenever nums[read] differs from the last kept value nums[write-1], write it at nums[write] and increment write.
Return write as the new length; the first write elements form the deduplicated array in-place.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        if (n == 0) return 0;

        int write = 1; // next position to write a new unique value
        for (int read = 1; read < n; ++read) {
            // Since sorted, a new unique appears when current differs from last kept
            if (nums[read] != nums[write - 1]) {
                nums[write++] = nums[read];
            }
        }
        return write;
    }
};
```