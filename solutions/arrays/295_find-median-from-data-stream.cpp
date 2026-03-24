```cpp
/*
Problem: Find Median from Data Stream
Problem Number: 295
Difficulty: Hard
Topic: arrays
Date: 2026-03-24

Approach:
Maintain two heaps: a max-heap for the lower half of numbers and a min-heap for the upper half.
On insertion, push into the appropriate heap, then rebalance so that the size difference is at most 1 and the max-heap has the extra element when odd.
The median is either the top of the max-heap (odd count) or the average of both heap tops (even count).

Time Complexity: O(log n) per addNum, O(1) per findMedian
Space Complexity: O(n)
*/

#include <queue>
#include <vector>
#include <functional>

class MedianFinder {
private:
    // lower: max-heap (stores smaller half), upper: min-heap (stores larger half)
    std::priority_queue<int> lower;
    std::priority_queue<int, std::vector<int>, std::greater<int>> upper;

    void rebalance() {
        // Ensure: lower.size() == upper.size() or lower.size() == upper.size() + 1
        if (lower.size() < upper.size()) {
            lower.push(upper.top());
            upper.pop();
        } else if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        }
    }

public:
    MedianFinder() = default;

    void addNum(int num) {
        if (lower.empty() || num <= lower.top()) lower.push(num);
        else upper.push(num);
        rebalance();
    }

    double findMedian() {
        if (lower.size() == upper.size()) {
            // Use double to avoid overflow concerns; sum in double.
            return (static_cast<double>(lower.top()) + static_cast<double>(upper.top())) / 2.0;
        }
        return static_cast<double>(lower.top());
    }
};

class Solution {
public:
    // LeetCode expects MedianFinder class for this problem; Solution is provided per prompt format.
};
```