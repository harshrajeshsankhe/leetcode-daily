```cpp
/*
Problem: Counting Bits
Problem Number: 338
Difficulty: Easy
Topic: arrays
Date: 2026-03-24

Approach:
Use dynamic programming with the identity: popcount(i) = popcount(i >> 1) + (i & 1).
Compute answers from 0..n in increasing order so each state depends only on a smaller index.
This yields a single pass with O(1) work per number.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};
```