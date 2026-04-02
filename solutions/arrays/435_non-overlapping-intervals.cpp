```cpp
/*
Problem: Non-overlapping Intervals
Problem Number: 435
Difficulty: Medium
Topic: arrays
Date: 2026-04-02

Approach:
Sort intervals by their end time and greedily keep the interval that finishes earliest to maximize how many non-overlapping intervals can be kept. 
Scan in order, and whenever an interval starts before the end of the last kept interval, we must remove one interval; removing the one with the larger end is optimal, which is exactly ensured by sorting by end.
The answer is total intervals minus the maximum number of non-overlapping intervals kept.

Time Complexity: O(n log n)
Space Complexity: O(1) extra (sorting aside)
*/

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        const int n = (int)intervals.size();
        if (n <= 1) return 0;

        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      if (a[1] != b[1]) return a[1] < b[1]; // earlier finish first
                      return a[0] < b[0];
                  });

        int kept = 1;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; ++i) {
            // Non-overlap condition: current start >= last kept end
            if (intervals[i][0] >= lastEnd) {
                ++kept;
                lastEnd = intervals[i][1];
            }
            // else overlap: we effectively remove this interval (since it ends later or equal due to sorting)
        }

        return n - kept;
    }
};
```