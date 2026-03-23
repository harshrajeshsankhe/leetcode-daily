```cpp
/*
Problem: Find Minimum in Rotated Sorted Array
Problem Number: 153
Difficulty: Medium
Topic: binary-search
Date: 2026-03-23

Approach:
Use binary search on the rotated sorted array with distinct elements. Compare mid with the rightmost element: if nums[mid] > nums[r], the minimum lies in (mid, r]; otherwise it lies in [l, mid]. Continue shrinking the range until l == r, which points to the minimum.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = (int)nums.size() - 1;

        // Invariant: the minimum is always within [l, r]
        while (l < r) {
            int m = l + (r - l) / 2;

            // If mid element is greater than the rightmost, min is to the right of mid
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else {
                // Otherwise min is at mid or to the left of mid
                r = m;
            }
        }
        return nums[l];
    }
};
```