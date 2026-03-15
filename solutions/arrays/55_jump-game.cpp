```cpp
/*
Problem: Jump Game
Problem Number: 55
Difficulty: Medium
Topic: arrays
Date: 2026-03-15

Approach:
Use a greedy scan maintaining the farthest index reachable so far. For each position i, if i is beyond the current farthest reach, the end is unreachable; otherwise update the farthest reach with i + nums[i]. If the farthest reach ever reaches or surpasses the last index, return true.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        int n = (int)nums.size();
        int far = 0; // farthest reachable index so far

        for (int i = 0; i < n; ++i) {
            if (i > far) return false; // cannot even reach i
            far = std::max(far, i + nums[i]);
            if (far >= n - 1) return true; // can reach or pass the end
        }
        return true; // single element or already ensured reachability throughout
    }
};
```