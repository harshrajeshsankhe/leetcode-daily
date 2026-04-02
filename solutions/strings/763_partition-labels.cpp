```cpp
/*
Problem: Partition Labels
Problem Number: 763
Difficulty: Medium
Topic: strings
Date: 2026-04-02

Approach:
First record the last index where each character appears in the string. Then scan left to right, maintaining the farthest last occurrence among characters seen so far as the current partition's end. When the current index reaches this end, we close the partition and start a new one after it.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        // Last occurrence for each lowercase letter.
        int last[26];
        for (int i = 0; i < 26; ++i) last[i] = -1;

        for (int i = 0; i < (int)s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }

        std::vector<int> result;
        int start = 0, end = 0;

        for (int i = 0; i < (int)s.size(); ++i) {
            end = std::max(end, last[s[i] - 'a']); // extend partition if needed
            if (i == end) {                        // partition complete
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};
```