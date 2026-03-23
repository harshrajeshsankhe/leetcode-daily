```cpp
/*
Problem: Missing Number
Problem Number: 268
Difficulty: Easy
Topic: arrays
Date: 2026-03-23

Approach:
Use XOR to cancel out matching values between the expected range [0..n] and the given array.
Initialize ans = n, then XOR ans with every index i and value nums[i]. All numbers that appear in both sets cancel, leaving only the missing number.
This avoids overflow issues from summation and runs in linear time with constant extra space.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = n; // include n since indices go 0..n-1 but numbers go 0..n
        for (int i = 0; i < n; ++i) {
            ans ^= i ^ nums[i];
        }
        return ans;
    }
};
```