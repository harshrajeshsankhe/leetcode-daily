```cpp
/*
Problem: Sliding Window Maximum
Problem Number: 239
Difficulty: Hard
Topic: arrays
Date: 2026-04-02

Approach:
Maintain a deque of indices in decreasing order of their corresponding values, so the front always stores the index of the current window's maximum.
For each new element, remove indices from the back while their values are <= the new value, then push the new index.
Before recording an answer, pop the front if it is outside the current window; the maximum for each window is nums[dq.front()].

Time Complexity: O(n)
Space Complexity: O(k)
*/

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        const int n = (int)nums.size();
        if (n == 0 || k <= 0) return {};
        if (k == 1) return nums;

        std::deque<int> dq;              // stores indices, values are in decreasing order
        std::vector<int> ans;
        ans.reserve(std::max(0, n - k + 1));

        for (int i = 0; i < n; ++i) {
            // Remove indices that are out of the current window [i-k+1, i]
            while (!dq.empty() && dq.front() <= i - k) dq.pop_front();

            // Maintain decreasing order: remove smaller/equal elements from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();

            dq.push_back(i);

            // Window becomes valid when i >= k-1
            if (i >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
```