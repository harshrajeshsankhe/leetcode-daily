```cpp
/*
Problem: Palindromic Substrings
Problem Number: 647
Difficulty: Medium
Topic: strings
Date: 2026-04-02

Approach:
Count palindromes by expanding around every possible center. Each palindrome is uniquely identified by its center (either a character for odd length or a gap between characters for even length), so we try all 2*n-1 centers and expand while the ends match, accumulating the count. This achieves optimal practical performance with O(1) extra space.

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int countSubstrings(const std::string& s) {
        const int n = (int)s.size();
        long long ans = 0;

        auto expand = [&](int l, int r) {
            long long cnt = 0;
            while (l >= 0 && r < n && s[l] == s[r]) {
                ++cnt;
                --l;
                ++r;
            }
            return cnt;
        };

        for (int c = 0; c < n; ++c) {
            ans += expand(c, c);       // odd-length palindromes
            ans += expand(c, c + 1);   // even-length palindromes
        }

        return (int)ans;
    }
};
```