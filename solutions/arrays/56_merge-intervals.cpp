```cpp
/*
Problem: Merge Intervals
Problem Number: 56
Difficulty: Medium
Topic: arrays
Date: 2026-03-15

Approach:
Sort intervals by start (and end as tie-breaker), then scan from left to right maintaining the current merged interval.
If the next interval overlaps (its start <= current end), extend the current end to the maximum of both ends; otherwise, push the current interval and start a new one.
This greedy scan is optimal after sorting because any overlap must be resolved locally in sorted order.

Time Complexity: O(n log n)
Space Complexity: O(1) auxiliary (excluding output)
*/

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) return {};

        std::sort(intervals.begin(), intervals.end(),
                  [](const std::vector<int>& a, const std::vector<int>& b) {
                      if (a[0] != b[0]) return a[0] < b[0];
                      return a[1] < b[1];
                  });

        std::vector<std::vector<int>> res;
        res.reserve(intervals.size());

        int curL = intervals[0][0];
        int curR = intervals[0][1];

        for (int i = 1; i < (int)intervals.size(); ++i) {
            const int l = intervals[i][0];
            const int r = intervals[i][1];

            if (l <= curR) {
                // Overlap: merge by extending the right boundary.
                if (r > curR) curR = r;
            } else {
                // Disjoint: finalize current interval and start a new one.
                res.push_back({curL, curR});
                curL = l;
                curR = r;
            }
        }

        res.push_back({curL, curR});
        return res;
    }
};
```