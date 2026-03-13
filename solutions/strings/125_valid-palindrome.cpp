```cpp
/*
Problem: Valid Palindrome
Problem Number: 125
Difficulty: Easy
Topic: strings
Date: 2026-03-13

Approach:
Use two pointers starting from both ends of the string. Move each pointer inward skipping non-alphanumeric characters, and compare the remaining characters case-insensitively. If any mismatch occurs, return false; otherwise, if pointers cross, the string is a valid palindrome.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(std::string s) {
        int i = 0, j = (int)s.size() - 1;

        while (i < j) {
            while (i < j && !isAlnumAscii(s[i])) ++i;
            while (i < j && !isAlnumAscii(s[j])) --j;

            if (i < j) {
                if (toLowerAscii(s[i]) != toLowerAscii(s[j])) return false;
                ++i; --j;
            }
        }
        return true;
    }

private:
    static inline bool isAlnumAscii(char c) {
        unsigned char uc = static_cast<unsigned char>(c);
        return (uc >= '0' && uc <= '9') ||
               (uc >= 'A' && uc <= 'Z') ||
               (uc >= 'a' && uc <= 'z');
    }

    static inline char toLowerAscii(char c) {
        if (c >= 'A' && c <= 'Z') return char(c - 'A' + 'a');
        return c;
    }
};
```