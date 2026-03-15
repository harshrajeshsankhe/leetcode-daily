```cpp
/*
Problem: Maximum Subarray
Problem Number: 53
Difficulty: Medium
Topic: arrays
Date: 2026-03-15

Approach:
Use Kadane's algorithm (dynamic programming) to scan the array once. Maintain the best subarray sum ending at the current index, either by extending the previous subarray or starting fresh at the current element. Track the global maximum seen so far during the scan.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int bestEndingHere = nums[0];
        int bestOverall = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i) {
            // Either extend the previous subarray or start a new one at i
            bestEndingHere = std::max(nums[i], bestEndingHere + nums[i]);
            bestOverall = std::max(bestOverall, bestEndingHere);
        }
        return bestOverall;
    }
};
```