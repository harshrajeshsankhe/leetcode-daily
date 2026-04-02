/*
Problem: Find All Anagrams in a String
Problem Number: 438
Difficulty: Medium
Topic: strings
Date: 2026-04-02

Approach:
Use a fixed-size sliding window of length |p| over s while maintaining character frequency differences between the window and p.
Track how many characters currently match the needed counts; when all 26 match, the window start is an anagram index.
Update counts in O(1) when the window moves by adding the new right character and removing the left character.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = (int)s.size(), m = (int)p.size();
        vector<int> ans;
        if (m > n) return ans;

        // diff[c] = window_count[c] - p_count[c]
        int diff[26] = {0};

        for (char ch : p) diff[ch - 'a']--;
        for (int i = 0; i < m; ++i) diff[s[i] - 'a']++;

        int matches = 0; // number of letters with diff == 0
        for (int c = 0; c < 26; ++c) matches += (diff[c] == 0);

        if (matches == 26) ans.push_back(0);

        auto apply = [&](int idx, int delta) {
            // Update diff[idx] by delta and maintain matches count.
            bool wasZero = (diff[idx] == 0);
            diff[idx] += delta;
            bool nowZero = (diff[idx] == 0);
            if (wasZero && !nowZero) --matches;
            else if (!wasZero && nowZero) ++matches;
        };

        for (int r = m; r < n; ++r) {
            // Add new right character
            apply(s[r] - 'a', +1);
            // Remove left character
            apply(s[r - m] - 'a', -1);

            if (matches == 26) ans.push_back(r - m + 1);
        }

        return ans;
    }
};