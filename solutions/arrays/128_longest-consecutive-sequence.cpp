```cpp
/*
Problem: Longest Consecutive Sequence
Problem Number: 128
Difficulty: Medium
Topic: arrays
Date: 2026-03-18

Approach:
Insert all numbers into an unordered_set for O(1) average membership checks. For each number that does not have a predecessor (x-1 not in the set), treat it as the start of a sequence and extend forward while consecutive numbers exist, tracking the maximum length. This ensures each number is visited at most once as part of an extension, yielding linear expected time.

Time Complexity: O(n) average (unordered_set), O(n^2) worst-case with pathological hashing
Space Complexity: O(n)
*/

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        std::unordered_set<int> s;
        s.reserve(nums.size() * 2); // reduce rehashing
        s.max_load_factor(0.7f);

        for (int x : nums) s.insert(x);

        int best = 0;
        for (int x : s) {
            // Only start counting from sequence starts (no predecessor).
            if (s.find(x - 1) != s.end()) continue;

            int cur = x;
            int len = 1;
            while (s.find(cur + 1) != s.end()) {
                ++cur;
                ++len;
            }
            if (len > best) best = len;
        }
        return best;
    }
};
```