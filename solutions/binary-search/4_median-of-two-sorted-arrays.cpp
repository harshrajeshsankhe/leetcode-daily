```cpp
/*
Problem: Median of Two Sorted Arrays
Problem Number: 4
Difficulty: Hard
Topic: binary-search
Date: 2026-03-15

Approach:
Use binary search on the smaller array to find a partition such that all elements on the left side of both arrays are <= all elements on the right side.
Let i be the cut in the first array and j be the cut in the second so that i + j = (m + n + 1) / 2, ensuring the left side has the extra element when total length is odd.
When the partition is valid (A[i-1] <= B[j] and B[j-1] <= A[i]), compute the median from the boundary elements around the cuts.

Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)
*/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to keep binary search minimal.
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        const int m = (int)nums1.size();
        const int n = (int)nums2.size();
        const int leftSize = (m + n + 1) / 2; // Left partition size (includes median when odd).

        int lo = 0, hi = m; // i in [0..m]
        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = leftSize - i;

            // Boundary values around cuts; use sentinels to avoid bounds checks.
            int Aleft  = (i == 0) ? std::numeric_limits<int>::min() : nums1[i - 1];
            int Aright = (i == m) ? std::numeric_limits<int>::max() : nums1[i];
            int Bleft  = (j == 0) ? std::numeric_limits<int>::min() : nums2[j - 1];
            int Bright = (j == n) ? std::numeric_limits<int>::max() : nums2[j];

            // Check if we found the correct partition.
            if (Aleft <= Bright && Bleft <= Aright) {
                // Correct partition: compute median.
                int leftMax = std::max(Aleft, Bleft);
                if (((m + n) & 1) == 1) return (double)leftMax;

                int rightMin = std::min(Aright, Bright);
                return (leftMax + rightMin) / 2.0;
            }

            // Adjust binary search based on which side violates ordering.
            if (Aleft > Bright) {
                // Aleft too big: move i left.
                hi = i - 1;
            } else {
                // Bleft > Aright: move i right.
                lo = i + 1;
            }
        }

        // Should never reach here for valid input.
        return 0.0;
    }
};
```