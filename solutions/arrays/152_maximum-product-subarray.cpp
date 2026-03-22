```cpp
/*
Problem: Maximum Product Subarray
Problem Number: 152
Difficulty: Medium
Topic: arrays
Date: 2026-03-22

Approach:
Use dynamic programming while scanning the array, tracking the maximum and minimum product ending at the current index.
A negative number can swap roles of max/min, so keep both; when encountering a number, update maxEnd and minEnd using
the previous values and the current element itself as a restart candidate. The global answer is the maximum maxEnd seen.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        // Constraints guarantee at least one element.
        long long maxEnd = nums[0];  // maximum product ending at current position
        long long minEnd = nums[0];  // minimum product ending at current position (important for negatives)
        long long ans = nums[0];

        for (int i = 1; i < (int)nums.size(); ++i) {
            long long x = nums[i];

            // Preserve previous values before updating.
            long long prevMax = maxEnd, prevMin = minEnd;

            // Either start new subarray at x, or extend previous max/min subarray.
            maxEnd = std::max({x, x * prevMax, x * prevMin});
            minEnd = std::min({x, x * prevMax, x * prevMin});

            ans = std::max(ans, maxEnd);
        }

        return (int)ans;
    }
};
```