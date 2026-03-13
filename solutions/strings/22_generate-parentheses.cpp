```cpp
/*
Problem: Generate Parentheses
Problem Number: 22
Difficulty: Medium
Topic: strings
Date: 2026-03-13

Approach:
Use backtracking to build the string character by character while maintaining counts of open and close parentheses used.
We can always add '(' if we haven't used n opens yet, and we can add ')' only if it won't make the prefix invalid (i.e., close < open).
When the constructed string reaches length 2*n, it is a valid sequence and is added to the answer.

Time Complexity: O(Cn * n) where Cn is the nth Catalan number (number of valid sequences), and n accounts for string construction/output.
Space Complexity: O(n) recursion depth plus O(Cn * n) for storing all results.
*/

class Solution {
public:
    void dfs(int n, int open, int close, std::string &cur, std::vector<std::string> &res) {
        if ((int)cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }

        // Try adding '(' if we still can.
        if (open < n) {
            cur.push_back('(');
            dfs(n, open + 1, close, cur, res);
            cur.pop_back();
        }

        // Try adding ')' only if it keeps the prefix valid.
        if (close < open) {
            cur.push_back(')');
            dfs(n, open, close + 1, cur, res);
            cur.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        std::string cur;
        cur.reserve(2 * n);
        dfs(n, 0, 0, cur, res);
        return res;
    }
};
```