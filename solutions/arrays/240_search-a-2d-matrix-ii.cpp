```cpp
/*
Problem: Search a 2D Matrix II
Problem Number: 240
Difficulty: Medium
Topic: arrays
Date: 2026-03-26

Approach:
Use the monotonic property of rows and columns by starting from the top-right corner.
If the current value is larger than target, move left to decrease; if smaller, move down to increase.
This eliminates one row or one column at each step until the target is found or bounds are exceeded.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = (int)matrix.size();
        if (m == 0) return false;
        int n = (int)matrix[0].size();
        if (n == 0) return false;

        int r = 0, c = n - 1; // start at top-right
        while (r < m && c >= 0) {
            int x = matrix[r][c];
            if (x == target) return true;
            if (x > target) --c;   // move left to smaller values
            else ++r;              // move down to larger values
        }
        return false;
    }
};
```