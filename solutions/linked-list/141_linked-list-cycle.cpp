```cpp
/*
Problem: Linked List Cycle
Problem Number: 141
Difficulty: Easy
Topic: linked-list
Date: 2026-03-15

Approach:
Use Floyd's Tortoise and Hare algorithm with two pointers moving at different speeds.
If the list has a cycle, the fast pointer will eventually meet the slow pointer inside the cycle.
If fast reaches nullptr (end of list), no cycle exists.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Floyd's cycle detection (two pointers)
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps
            if (slow == fast) return true;
        }
        return false; // reached end => no cycle
    }
};
```