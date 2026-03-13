```cpp
/*
Problem: 3Sum
Problem Number: 15
Difficulty: Medium
Topic: arrays
Date: 2026-03-13

Approach:
Sort the array, then fix each index i as the first element of the triplet and use a two-pointer sweep (l, r) to find pairs summing to -nums[i].
Skip duplicates for i, and after finding a valid triplet, advance l and r past equal values to avoid repeating triplets.
Early-stop when nums[i] > 0 since the remaining values are non-negative and cannot sum to zero.

Time Complexity: O(n^2)
Space Complexity: O(1) extra (excluding output)
*/

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        const int n = (int)nums.size();
        if (n < 3) return res;

        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) break;                 // cannot make sum 0 with all remaining >= nums[i] > 0
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicate first element

            int l = i + 1, r = n - 1;
            while (l < r) {
                long long sum = (long long)nums[i] + nums[l] + nums[r];
                if (sum < 0) {
                    ++l;
                } else if (sum > 0) {
                    --r;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    int leftVal = nums[l], rightVal = nums[r];
                    while (l < r && nums[l] == leftVal) ++l;   // skip duplicates of second element
                    while (l < r && nums[r] == rightVal) --r;  // skip duplicates of third element
                }
            }
        }
        return res;
    }
};
```