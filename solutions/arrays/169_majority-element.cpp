```cpp
/*
Problem: Majority Element
Problem Number: 169
Difficulty: Easy
Topic: arrays
Date: 2026-03-15

Approach:
Use the Boyer–Moore majority vote algorithm, which maintains a candidate and a counter while scanning the array once.
When the counter drops to zero, set the current element as the new candidate; otherwise increment/decrement based on equality.
Because a majority element (> n/2) is guaranteed to exist, the final candidate is the answer.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
                count = 1;
            } else if (x == candidate) {
                ++count;
            } else {
                --count;
            }
        }

        return candidate; // Guaranteed to be the majority element by problem statement.
    }
};
```