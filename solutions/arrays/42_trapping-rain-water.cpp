```cpp
/*
Problem: Trapping Rain Water
Problem Number: 42
Difficulty: Hard
Topic: arrays
Date: 2026-03-15

Approach:
Use two pointers starting at both ends while tracking the maximum height seen so far from the left and right.
At each step, advance the pointer with the smaller current height because the trapped water there is bounded by its side's max.
Accumulate water as (leftMax - height[l]) or (rightMax - height[r]) when the current bar is below the corresponding max.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int trap(std::vector<int>& height) {
        int n = (int)height.size();
        if (n < 3) return 0;

        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        long long water = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                // Left side is the limiting side; right side has at least height[r] >= height[l].
                leftMax = std::max(leftMax, height[l]);
                water += (leftMax - height[l]);
                ++l;
            } else {
                // Right side is the limiting side.
                rightMax = std::max(rightMax, height[r]);
                water += (rightMax - height[r]);
                --r;
            }
        }

        return (int)water;
    }
};
```