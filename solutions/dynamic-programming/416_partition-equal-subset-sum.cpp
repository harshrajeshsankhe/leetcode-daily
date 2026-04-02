```cpp
/*
Problem: Partition Equal Subset Sum
Problem Number: 416
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-04-02

Approach:
Compute the total sum; if it's odd, splitting into two equal subsets is impossible. Otherwise, reduce to a subset-sum problem targeting sum/2, using 1D DP where dp[s] indicates whether sum s is achievable. Iterate numbers and update dp backwards to ensure each number is used at most once; early-exit once dp[target] becomes true.

Time Complexity: O(n * target)
Space Complexity: O(target)
*/

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        long long total = 0;
        for (int x : nums) total += x;
        if (total & 1LL) return false;
        int target = static_cast<int>(total / 2);

        // dp[s] = whether some subset sums to s
        std::vector<char> dp(target + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            if (x > target) continue; // cannot contribute to sums <= target
            for (int s = target; s >= x; --s) {
                if (dp[s - x]) dp[s] = 1;
            }
            if (dp[target]) return true; // early exit
        }
        return dp[target];
    }
};
```