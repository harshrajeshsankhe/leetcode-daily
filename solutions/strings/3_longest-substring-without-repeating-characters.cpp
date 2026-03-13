```cpp
/*
Problem: Longest Substring Without Repeating Characters
Problem Number: 3
Difficulty: Medium
Topic: strings
Date: 2026-03-13

Approach:
Use a sliding window with two pointers [l..r] and track the last seen index of each character.
When encountering a character that already exists in the current window, move l to one past its last occurrence.
Update the answer with the maximum window size as we expand r across the string.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // ASCII table size; LeetCode input is typically standard char range.
        // Using 256 keeps space constant and fast.
        std::vector<int> last(256, -1);

        int best = 0;
        int l = 0; // left boundary of current window (inclusive)

        for (int r = 0; r < (int)s.size(); ++r) {
            unsigned char c = static_cast<unsigned char>(s[r]);

            // If c was seen inside the current window, shrink from the left.
            if (last[c] >= l) l = last[c] + 1;

            last[c] = r;
            best = std::max(best, r - l + 1);
        }

        return best;
    }
};
```