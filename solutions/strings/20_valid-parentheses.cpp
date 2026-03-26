```cpp
/*
Problem: Valid Parentheses
Problem Number: 20
Difficulty: Easy
Topic: strings
Date: 2026-03-26

Approach:
Use a stack to store opening brackets as we scan the string left to right. When encountering a closing bracket, it must match the most recent unmatched opening bracket on the stack; otherwise the string is invalid. At the end, the string is valid only if the stack is empty.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(std::string s) {
        std::vector<char> st;
        st.reserve(s.size());

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push_back(c);
            } else {
                if (st.empty()) return false;
                char top = st.back();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
                st.pop_back();
            }
        }
        return st.empty();
    }
};
```