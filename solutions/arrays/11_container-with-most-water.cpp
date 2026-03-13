```cpp
/*
Problem: Container With Most Water
Problem Number: 11
Difficulty: Medium
Topic: arrays
Date: 2026-03-13

Approach:
Use two pointers starting at both ends of the array and compute the area formed by the lines at these pointers.
The limiting height is the smaller of the two, so to potentially increase area we move the pointer with the smaller height inward.
Track the maximum area over all pointer positions until the pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int n = (int)height.size();
        int l = 0, r = n - 1;
        long long best = 0;

        while (l < r) {
            int h = std::min(height[l], height[r]);
            long long area = 1LL * h * (r - l);
            if (area > best) best = area;

            // Move the pointer that limits the height (greedy).
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return (int)best;
    }
};
```