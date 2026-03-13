```cpp
/*
Problem: Letter Combinations of a Phone Number
Problem Number: 17
Difficulty: Medium
Topic: strings
Date: 2026-03-13

Approach:
Use backtracking to build combinations character by character. For each digit, iterate over its mapped letters and append one letter to the current string, recurse to the next digit, then undo (pop) the choice. When the built string length equals the digits length, add it to the answer.

Time Complexity: O(4^n) where n = digits.size() (each digit expands to at most 4 letters)
Space Complexity: O(n) recursion depth (excluding output storage)
*/

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        static const std::string mp[10] = {
            "",    "",    "abc",  "def",  "ghi",
            "jkl", "mno", "pqrs", "tuv",  "wxyz"
        };

        std::vector<std::string> res;
        std::string cur;
        cur.reserve(digits.size());

        // Optional: reserve approximate output size to reduce reallocations.
        size_t cap = 1;
        for (char d : digits) cap *= mp[d - '0'].size();
        res.reserve(cap);

        auto dfs = [&](auto&& self, int i) -> void {
            if (i == (int)digits.size()) {
                res.push_back(cur);
                return;
            }
            const std::string& letters = mp[digits[i] - '0'];
            for (char ch : letters) {
                cur.push_back(ch);
                self(self, i + 1);
                cur.pop_back();
            }
        };

        dfs(dfs, 0);
        return res;
    }
};
```