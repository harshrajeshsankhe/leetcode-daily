```cpp
/*
Problem: Longest Substring Without Repeating Characters
Problem Number: 3
Difficulty: Medium
Topic: strings
Date: 2026-03-15

Approach:
Use a sliding window with two pointers and an array that stores the last seen index of each character.
As we expand the right pointer, if the character was seen inside the current window, move the left pointer
to one position after its last occurrence. Track the maximum window length during the scan.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // ASCII-based constraints; for general bytes this still works.
        std::vector<int> last(256, -1);

        int best = 0;
        int l = 0; // left boundary of current window

        for (int r = 0; r < (int)s.size(); ++r) {
            unsigned char c = static_cast<unsigned char>(s[r]);

            // If character was seen within current window, shrink from left.
            if (last[c] >= l) l = last[c] + 1;

            last[c] = r;
            best = std::max(best, r - l + 1);
        }
        return best;
    }
};
```