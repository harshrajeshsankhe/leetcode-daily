/*
Problem: Unique Paths
Problem Number: 62
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-03-15

Approach:
The robot must make exactly (m-1) down moves and (n-1) right moves in any order, so the number of unique paths is the binomial coefficient C(m+n-2, m-1).
Compute this value iteratively using a multiplicative formula to avoid factorials and reduce overflow risk by simplifying at each step with 64-bit arithmetic.
This yields an O(min(m,n)) time, O(1) space solution.

Time Complexity: O(min(m, n))
Space Complexity: O(1)
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Total moves: (m-1) downs and (n-1) rights
        long long N = (long long)m + (long long)n - 2; // total steps
        long long K = (long long)std::min(m - 1, n - 1); // choose smaller for fewer iterations

        long long res = 1;
        // Compute C(N, K) = product_{i=1..K} (N-K+i)/i
        for (long long i = 1; i <= K; ++i) {
            res = res * (N - K + i) / i; // exact division at each step
        }
        return (int)res;
    }
};