```cpp
/*
Problem: Climbing Stairs
Problem Number: 70
Difficulty: Easy
Topic: dynamic-programming
Date: 2026-03-13

Approach:
The number of ways to reach step i equals the sum of ways to reach steps i-1 and i-2, since the last move can be 1 or 2 steps. This forms a Fibonacci-like recurrence with base cases f(0)=1 and f(1)=1. We compute iteratively while keeping only the last two values to achieve constant space.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int climbStairs(int n) {
        // f(0)=1 (one way: do nothing), f(1)=1
        long long a = 1; // f(i-2)
        long long b = 1; // f(i-1)
        for (int i = 2; i <= n; ++i) {
            long long c = a + b; // f(i)
            a = b;
            b = c;
        }
        return static_cast<int>(b);
    }
};
```