```cpp
/*
Problem: Kth Largest Element in an Array
Problem Number: 215
Difficulty: Medium
Topic: arrays
Date: 2026-03-25

Approach:
Use iterative Quickselect with a randomized 3-way partition (Dutch National Flag) around a pivot.
This partitions the array into elements < pivot, == pivot, and > pivot, then narrows the search range
to the part containing the target index (n - k for kth largest). Randomization prevents worst-case
behavior on adversarial inputs, giving expected linear time.

Time Complexity: Expected O(n), Worst-case O(n^2)
Space Complexity: O(1)
*/

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        const int n = (int)nums.size();
        int target = n - k; // kth largest == (n-k)th smallest (0-indexed)

        int l = 0, r = n - 1;
        while (l <= r) {
            // Random pivot index in [l, r]
            int pivotIdx = l + (int)(rng() % (uint64_t)(r - l + 1));
            int pivot = nums[pivotIdx];

            // 3-way partition: [l..lt-1] < pivot, [lt..gt] == pivot, [gt+1..r] > pivot
            int lt = l, i = l, gt = r;
            while (i <= gt) {
                if (nums[i] < pivot) {
                    std::swap(nums[lt++], nums[i++]);
                } else if (nums[i] > pivot) {
                    std::swap(nums[i], nums[gt--]);
                } else {
                    ++i;
                }
            }

            if (target < lt) {
                r = lt - 1;
            } else if (target > gt) {
                l = gt + 1;
            } else {
                return nums[target]; // target lies in the == pivot region
            }
        }
        return -1; // Unreachable for valid inputs
    }

private:
    // Simple fast RNG (xorshift64*) to avoid overhead of <random> in tight loops
    static uint64_t rng() {
        static uint64_t x = 88172645463325252ull;
        x ^= x >> 12;
        x ^= x << 25;
        x ^= x >> 27;
        return x * 2685821657736338717ull;
    }
};
```