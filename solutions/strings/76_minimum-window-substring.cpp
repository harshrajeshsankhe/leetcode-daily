/*
Problem: Minimum Window Substring
Problem Number: 76
Difficulty: Hard
Topic: strings
Date: 2026-03-22

Approach:
Use a sliding window with two pointers over s while tracking required character counts from t. Expand the right pointer to include characters, and when all required characters are satisfied, shrink from the left to minimize the window while maintaining validity. Track the best (smallest) valid window encountered and return it.

Time Complexity: O(n), where n = s.size()
Space Complexity: O(1), using fixed-size frequency arrays (ASCII)
*/

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (t.empty() || s.empty() || t.size() > s.size()) return "";

        // Frequency needed for each ASCII character
        int need[128] = {0};
        for (char c : t) need[(unsigned char)c]++;

        int missing = (int)t.size();  // total remaining required characters (with multiplicity)
        int bestLen = INT_MAX, bestL = 0;

        int l = 0;
        for (int r = 0; r < (int)s.size(); ++r) {
            unsigned char cr = (unsigned char)s[r];

            // If this character is still needed (>0), it reduces missing.
            if (need[cr] > 0) --missing;
            // Decrease need; can go negative meaning surplus in window.
            --need[cr];

            // When window satisfies all requirements, try to shrink from left.
            while (missing == 0) {
                int len = r - l + 1;
                if (len < bestLen) {
                    bestLen = len;
                    bestL = l;
                }

                unsigned char cl = (unsigned char)s[l++];
                // Put back character to need; if it becomes >0, we lost a required char.
                ++need[cl];
                if (need[cl] > 0) ++missing;
            }
        }

        return (bestLen == INT_MAX) ? "" : s.substr(bestL, bestLen);
    }
};