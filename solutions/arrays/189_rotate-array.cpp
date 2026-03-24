```cpp
/*
Problem: Rotate Array
Problem Number: 189
Difficulty: Medium
Topic: arrays
Date: 2026-03-24

Approach:
Rotate the array to the right by k using the in-place reversal technique. First reduce k modulo n, then reverse the entire array, reverse the first k elements, and finally reverse the remaining n-k elements. This achieves the desired rotation without extra memory.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = (int)nums.size();
        if (n <= 1) return;
        k %= n;
        if (k == 0) return;

        auto rev = [&](int l, int r) {
            while (l < r) std::swap(nums[l++], nums[r--]);
        };

        rev(0, n - 1);
        rev(0, k - 1);
        rev(k, n - 1);
    }
};
```