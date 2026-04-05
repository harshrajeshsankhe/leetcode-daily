```cpp
/*
Problem: Single Number
Problem Number: 136
Difficulty: Easy
Topic: arrays
Date: 2026-04-05

Approach:
Use bitwise XOR across all elements. XOR cancels out equal numbers (a ^ a = 0) and keeps the unique one (0 ^ x = x),
and since XOR is associative and commutative, the final accumulated value is the single number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int x = 0;
        for (int v : nums) x ^= v;
        return x;
    }
};
```