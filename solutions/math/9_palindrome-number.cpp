```cpp
/*
Problem: Palindrome Number
Problem Number: 9
Difficulty: Easy
Topic: math
Date: 2026-03-25

Approach:
Avoid converting to string. Negative numbers are not palindromes, and any positive number ending with 0 cannot be a palindrome unless it is 0. Reverse only the second half of the number (building rev) until rev >= remaining, then compare remaining with rev (even length) or remaining with rev/10 (odd length).

Time Complexity: O(log10(n))
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes due to the '-' sign.
        // Numbers ending in 0 are not palindromes unless the number is exactly 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int rev = 0; // reversed second half
        while (x > rev) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }

        // For even length: x == rev
        // For odd length: middle digit doesn't matter, so compare x with rev/10
        return (x == rev) || (x == rev / 10);
    }
};
```