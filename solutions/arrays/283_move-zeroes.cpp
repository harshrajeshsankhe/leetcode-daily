```cpp
/*
Problem: Move Zeroes
Problem Number: 283
Difficulty: Easy
Topic: arrays
Date: 2026-03-24

Approach:
Use a two-pointer compaction technique: iterate through the array and write every non-zero value to the next available position (write index).
After all non-zeros are placed in their original relative order, fill the remaining positions with zeros.
This performs the operation in-place with a single pass over the array and avoids unnecessary swaps.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0; // Next position to place a non-zero element

        // Compact all non-zero elements to the front, preserving order.
        for (int read = 0; read < (int)nums.size(); ++read) {
            if (nums[read] != 0) {
                nums[write++] = nums[read];
            }
        }

        // Fill the remaining positions with zeros.
        for (int i = write; i < (int)nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};
```