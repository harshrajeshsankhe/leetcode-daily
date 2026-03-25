```cpp
/*
Problem: House Robber II
Problem Number: 213
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-03-25

Approach:
Because the houses form a circle, the first and last houses cannot both be robbed; split into two linear cases:
rob houses in range [0..n-2] (exclude last) or [1..n-1] (exclude first), then take the maximum.
Each linear case is solved with classic DP using two variables: dp0 = best up to previous house, dp1 = best up to current,
updating as dp = max(dp1, dp0 + nums[i]) while rolling forward.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
    static int robLinear(const std::vector<int>& nums, int l, int r) {
        // Rob houses in inclusive range [l, r] with no adjacent picks.
        int dp0 = 0; // best up to i-2
        int dp1 = 0; // best up to i-1
        for (int i = l; i <= r; ++i) {
            int cur = std::max(dp1, dp0 + nums[i]);
            dp0 = dp1;
            dp1 = cur;
        }
        return dp1;
    }

public:
    int rob(std::vector<int>& nums) {
        const int n = (int)nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        // Two cases due to circular adjacency: exclude last or exclude first.
        return std::max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};
```