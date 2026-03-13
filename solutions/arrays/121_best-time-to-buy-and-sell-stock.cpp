```cpp
/*
Problem: Best Time to Buy and Sell Stock
Problem Number: 121
Difficulty: Easy
Topic: arrays
Date: 2026-03-13

Approach:
Scan prices once while tracking the minimum price seen so far (best buy). For each day, compute the profit if selling today after buying at that minimum, and keep the maximum such profit. This greedy one-pass method is equivalent to dynamic programming where we maintain the best state for "holding" and "not holding" with O(1) memory.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = INT_MAX;
        int bestProfit = 0;

        for (int p : prices) {
            if (p < minPrice) minPrice = p;                // Best (lowest) buy price so far
            bestProfit = std::max(bestProfit, p - minPrice); // Best profit if selling today
        }
        return bestProfit;
    }
};
```