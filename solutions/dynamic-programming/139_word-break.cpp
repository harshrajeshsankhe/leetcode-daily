```cpp
/*
Problem: Word Break
Problem Number: 139
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-03-22

Approach:
Use dynamic programming where dp[i] indicates whether the prefix s[0..i) can be segmented into dictionary words.
Store the dictionary in an unordered_set and iterate i from 1..n, trying only word lengths that exist in the dictionary
to check transitions dp[i] |= dp[i-len] && s.substr(i-len, len) in dict. This reduces unnecessary substring checks.

Time Complexity: O(n * K) average, where K is the number of distinct word lengths (substring hashing/compare cost included).
Space Complexity: O(n + |dict|)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int n = (int)s.size();
        unordered_set<string> dict;
        dict.reserve(wordDict.size() * 2);
        dict.max_load_factor(0.7f);

        vector<int> lens;
        lens.reserve(wordDict.size());
        {
            unordered_set<int> seenLen;
            seenLen.reserve(wordDict.size() * 2);
            seenLen.max_load_factor(0.7f);

            for (const string& w : wordDict) {
                dict.insert(w);
                int L = (int)w.size();
                if (seenLen.insert(L).second) lens.push_back(L);
            }
        }
        sort(lens.begin(), lens.end()); // helps break early when len > i

        vector<char> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i) {
            for (int L : lens) {
                if (L > i) break;
                if (!dp[i - L]) continue;
                // Create substring only when prior state is reachable.
                if (dict.find(s.substr(i - L, L)) != dict.end()) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```