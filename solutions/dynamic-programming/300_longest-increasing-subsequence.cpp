```cpp
/*
Problem: Longest Increasing Subsequence
Problem Number: 300
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-03-26

Approach:
Use the patience sorting idea: maintain an array tails where tails[k] is the minimum possible tail value of an increasing subsequence of length k+1.
For each number x, binary-search the first position in tails with value >= x and replace it with x (or append if none), keeping tails sorted.
The size of tails at the end equals the length of the LIS.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> tails;
        tails.reserve(nums.size());

        for (int x : nums) {
            // Find the first tail that is >= x (lower_bound) to keep subsequences strictly increasing.
            auto it = std::lower_bound(tails.begin(), tails.end(), x);
            if (it == tails.end()) {
                tails.push_back(x);          // Extend the longest subsequence found so far.
            } else {
                *it = x;                     // Improve (minimize) the tail for this length.
            }
        }
        return static_cast<int>(tails.size());
    }
};
```