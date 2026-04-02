```cpp
/*
Problem: Coin Change
Problem Number: 322
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-04-02

Approach:
Use bottom-up dynamic programming where dp[x] stores the minimum number of coins needed to make sum x.
Initialize dp[0]=0 and dp[x]=INF for x>0, then for each amount x from 1..amount, relax using all coins:
dp[x] = min(dp[x], dp[x-coin] + 1) when x>=coin. The answer is dp[amount] if reachable, otherwise -1.

Time Complexity: O(amount * n), where n is number of coins
Space Complexity: O(amount)
*/

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (coins.empty()) return -1;

        const int INF = amount + 1; // upper bound on minimum coins (if coin 1 exists)
        std::vector<int> dp(amount + 1, INF);
        dp[0] = 0;

        // Standard unbounded knapsack (min coins) DP
        for (int x = 1; x <= amount; ++x) {
            for (int c : coins) {
                if (c <= x && dp[x - c] != INF) {
                    dp[x] = std::min(dp[x], dp[x - c] + 1);
                }
            }
        }

        return (dp[amount] == INF) ? -1 : dp[amount];
    }
};
```