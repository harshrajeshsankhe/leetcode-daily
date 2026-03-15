```cpp
/*
Problem: Median of Two Sorted Arrays
Problem Number: 4
Difficulty: Hard
Topic: binary-search
Date: 2026-03-15

Approach:
Use binary search on the smaller array to find a partition such that the left halves of both arrays contain exactly half (or half+1) of the total elements, and every element on the left is <= every element on the right. At each step, adjust the partition based on boundary comparisons between the two arrays around the cut. Once a valid partition is found, compute the median from the max of left side (and min of right side for even total length).

Time Complexity: O(log(min(m,n)))
Space Complexity: O(1)
*/

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the smaller array to minimize binary search range.
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        const int m = (int)nums1.size();
        const int n = (int)nums2.size();
        const int total = m + n;
        const int half = (total + 1) / 2; // left side size (includes median when odd)

        int lo = 0, hi = m; // partition i in [0..m], partition j = half - i

        while (lo <= hi) {
            int i = lo + (hi - lo) / 2;
            int j = half - i;

            // Use sentinels for out-of-bounds.
            int Aleft  = (i == 0) ? std::numeric_limits<int>::min() : nums1[i - 1];
            int Aright = (i == m) ? std::numeric_limits<int>::max() : nums1[i];
            int Bleft  = (j == 0) ? std::numeric_limits<int>::min() : nums2[j - 1];
            int Bright = (j == n) ? std::numeric_limits<int>::max() : nums2[j];

            // Check if partition is valid.
            if (Aleft <= Bright && Bleft <= Aright) {
                // Found correct partition.
                int leftMax = std::max(Aleft, Bleft);
                if (total % 2 == 1) return (double)leftMax;

                int rightMin = std::min(Aright, Bright);
                return (leftMax + rightMin) / 2.0;
            }

            // Move partition i.
            if (Aleft > Bright) {
                // i is too big, move left.
                hi = i - 1;
            } else {
                // Bleft > Aright => i is too small, move right.
                lo = i + 1;
            }
        }

        // Inputs are guaranteed valid; this should not be reached.
        return 0.0;
    }
};
```