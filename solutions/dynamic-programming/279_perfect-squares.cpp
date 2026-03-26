```cpp
/*
Problem: Perfect Squares
Problem Number: 279
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-03-26

Approach:
Use number theory: by Lagrange's four-square theorem the answer is in {1,2,3,4}. First check if n is a perfect square (answer 1). Then reduce n by removing factors of 4 and if the remainder is 7 modulo 8, answer is 4 (Legendre's three-square theorem). Otherwise check if n can be expressed as sum of two squares (answer 2); if not, answer is 3.

Time Complexity: O(sqrt(n))
Space Complexity: O(1)
*/

class Solution {
    static bool isSquare(int x) {
        if (x < 0) return false;
        int r = (int)std::sqrt((double)x);
        return 1LL * r * r == x || 1LL * (r + 1) * (r + 1) == x;
    }

public:
    int numSquares(int n) {
        if (n <= 0) return 0;

        // 1) If n itself is a perfect square.
        if (isSquare(n)) return 1;

        // 2) Legendre: Reduce by factors of 4; if n == 8b+7 then answer is 4.
        int m = n;
        while ((m & 3) == 0) m >>= 2;          // divide by 4 while possible
        if ((m & 7) == 7) return 4;            // m % 8 == 7

        // 3) Check if n = a^2 + b^2 for some a,b => answer is 2.
        for (int a = 1; 1LL * a * a <= n; ++a) {
            int b2 = n - a * a;
            if (isSquare(b2)) return 2;
        }

        // 4) Otherwise answer is 3 by Lagrange + Legendre.
        return 3;
    }
};
```