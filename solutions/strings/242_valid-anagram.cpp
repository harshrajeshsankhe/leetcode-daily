```cpp
/*
Problem: Valid Anagram
Problem Number: 242
Difficulty: Easy
Topic: strings
Date: 2026-03-22

Approach:
If the lengths differ, they cannot be anagrams. Count character frequencies in one pass by incrementing for s and decrementing for t using a fixed-size array for lowercase English letters. Finally, verify all counts return to zero to confirm both strings contain the same multiset of characters.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;

        int freq[26] = {0};
        for (size_t i = 0; i < s.size(); ++i) {
            ++freq[s[i] - 'a'];
            --freq[t[i] - 'a'];
        }

        for (int c : freq) {
            if (c != 0) return false;
        }
        return true;
    }
};
```