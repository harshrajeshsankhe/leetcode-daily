/*
Problem: Largest Rectangle in Histogram
Problem Number: 84
Difficulty: Hard
Topic: arrays
Date: 2026-03-25

Approach:
Use a monotonic increasing stack of indices to find, for each bar, the nearest smaller bar on the left and right implicitly while scanning once.
When the current height is smaller than the stack top, pop indices and compute areas where the popped bar is the limiting height; the width spans between the new stack top + 1 and current index - 1.
Add a sentinel 0-height bar at the end to flush remaining bars and ensure all maximal rectangles are considered.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        const int n = (int)heights.size();
        std::vector<int> st;
        st.reserve(n + 1);

        long long best = 0;

        for (int i = 0; i <= n; ++i) {
            int curH = (i == n ? 0 : heights[i]); // sentinel to flush stack at end

            // Maintain increasing heights in stack
            while (!st.empty() && heights[st.back()] > curH) {
                int h = heights[st.back()];
                st.pop_back();

                // After popping, the new top is index of previous smaller element
                int leftLessIdx = st.empty() ? -1 : st.back();
                long long width = (long long)i - leftLessIdx - 1;
                best = std::max(best, width * h);
            }

            // Push current index (for i==n, we don't need to push sentinel)
            if (i < n) st.push_back(i);
        }

        return (int)best;
    }
};