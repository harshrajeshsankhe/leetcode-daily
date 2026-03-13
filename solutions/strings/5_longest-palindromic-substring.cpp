```cpp
/*
Problem: Longest Palindromic Substring
Problem Number: 5
Difficulty: Medium
Topic: strings
Date: 2026-03-13

Approach:
Use Manacher's algorithm to compute, in linear time, the maximum palindrome radius centered at every position for both odd and even length palindromes.
Transform the string by inserting separators to unify handling of odd/even palindromes, then expand using previously computed information to skip redundant comparisons.
Track the center with the largest radius and map it back to the original string indices to return the longest palindromic substring.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int n = (int)s.size();
        if (n <= 1) return s;

        // Transform s into t with separators to handle even/odd palindromes uniformly.
        // Example: "abba" -> "^#a#b#b#a#$"
        // '^' and '$' are sentinels to avoid bounds checks during expansion.
        std::string t;
        t.reserve(2 * n + 3);
        t.push_back('^');
        t.push_back('#');
        for (char c : s) {
            t.push_back(c);
            t.push_back('#');
        }
        t.push_back('$');

        int m = (int)t.size();
        std::vector<int> p(m, 0); // p[i] = radius (in t) of palindrome centered at i

        int center = 0, right = 0;
        int bestCenter = 0, bestLen = 0;

        for (int i = 1; i < m - 1; ++i) {
            int mirror = 2 * center - i;

            // Initialize p[i] using the mirror palindrome if within the current right boundary.
            if (i < right) p[i] = std::min(right - i, p[mirror]);

            // Expand around center i.
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) ++p[i];

            // Update center/right if the palindrome at i extends beyond right.
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            // Track the maximum radius.
            if (p[i] > bestLen) {
                bestLen = p[i];
                bestCenter = i;
            }
        }

        // Convert from transformed indices to original string indices.
        // In this transform, the start index in s is (bestCenter - bestLen) / 2.
        int start = (bestCenter - bestLen) / 2;
        return s.substr(start, bestLen);
    }
};
```