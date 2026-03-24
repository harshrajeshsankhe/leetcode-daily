```cpp
/*
Problem: House Robber
Problem Number: 198
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-03-24

Approach:
Use 1D dynamic programming with constant space: for each house, decide between skipping it (keep best so far)
or robbing it (add its money to best up to two houses back). Maintain two variables representing dp[i-2] and
dp[i-1], update iteratively, and return the final best.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int rob(std::vector<int>& nums) {
        long long prev2 = 0; // dp[i-2]
        long long prev1 = 0; // dp[i-1]
        for (int x : nums) {
            long long cur = std::max(prev1, prev2 + x);
            prev2 = prev1;
            prev1 = cur;
        }
        return static_cast<int>(prev1);
    }
};
```