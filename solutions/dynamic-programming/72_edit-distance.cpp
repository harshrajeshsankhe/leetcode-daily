```cpp
/*
Problem: Edit Distance
Problem Number: 72
Difficulty: Medium
Topic: dynamic-programming
Date: 2026-03-15

Approach:
Use classic dynamic programming where dp[i][j] is the minimum edits to convert word1[0..i) into word2[0..j). The transition considers insert, delete, and replace; if the last characters match, no extra cost is added. Optimize space by keeping only the previous and current rows (rolling array) since each state depends only on dp[i-1][*] and dp[i][j-1]. 

Time Complexity: O(n*m)
Space Complexity: O(m)
*/

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        const int n = (int)word1.size();
        const int m = (int)word2.size();

        // dp[j] = dp for current row; prev[j] = dp for previous row
        std::vector<int> prev(m + 1), cur(m + 1);

        // Base: convert empty prefix of word1 to word2[0..j): j insertions
        for (int j = 0; j <= m; ++j) prev[j] = j;

        for (int i = 1; i <= n; ++i) {
            // Base: convert word1[0..i) to empty word2: i deletions
            cur[0] = i;

            for (int j = 1; j <= m; ++j) {
                int cost = (word1[i - 1] == word2[j - 1]) ? 0 : 1;

                // delete:    prev[j] + 1      (delete word1[i-1])
                // insert:    cur[j-1] + 1     (insert word2[j-1])
                // replace:   prev[j-1] + cost (replace/match last char)
                cur[j] = std::min({ prev[j] + 1, cur[j - 1] + 1, prev[j - 1] + cost });
            }
            prev.swap(cur);
        }

        return prev[m];
    }
};
```