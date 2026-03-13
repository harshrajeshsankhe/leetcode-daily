```cpp
/*
Problem: Search in Rotated Sorted Array
Problem Number: 33
Difficulty: Medium
Topic: binary-search
Date: 2026-03-13

Approach:
Use modified binary search: at each step, determine which half (left or right) is sorted by comparing nums[l] and nums[mid].
If the target lies within the sorted half's range, move into that half; otherwise search the other half.
This preserves logarithmic time because each iteration discards half of the search interval.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = (int)nums.size() - 1;
        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            if (nums[mid] == target) return mid;

            // Determine which half is sorted.
            if (nums[l] <= nums[mid]) { // Left half is sorted.
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Target in left sorted half.
                } else {
                    l = mid + 1; // Target in right half.
                }
            } else { // Right half is sorted.
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // Target in right sorted half.
                } else {
                    r = mid - 1; // Target in left half.
                }
            }
        }
        return -1;
    }
};
```