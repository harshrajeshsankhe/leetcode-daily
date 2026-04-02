```cpp
/*
Problem: Longest Repeating Character Replacement
Problem Number: 424
Difficulty: Medium
Topic: strings
Date: 2026-04-02

Approach:
Use a sliding window with frequency counts of characters in the current window. Maintain the maximum frequency (maxFreq) of any single character seen in the window; the window is valid if (windowSize - maxFreq) <= k, otherwise shrink from the left. Track the largest valid window length; maxFreq can be kept as a non-decreasing upper bound, which preserves correctness and ensures linear time.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        int cnt[26] = {0};
        int n = (int)s.size();
        int l = 0, ans = 0;
        int maxFreq = 0;

        for (int r = 0; r < n; ++r) {
            int idxR = s[r] - 'A';
            maxFreq = std::max(maxFreq, ++cnt[idxR]);

            // If more than k replacements needed, shrink from left.
            while ((r - l + 1) - maxFreq > k) {
                --cnt[s[l] - 'A'];
                ++l;
            }

            ans = std::max(ans, r - l + 1);
        }
        return ans;
    }
};
```