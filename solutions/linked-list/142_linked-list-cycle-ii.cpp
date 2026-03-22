```cpp
/*
Problem: Linked List Cycle II
Problem Number: 142
Difficulty: Medium
Topic: linked-list
Date: 2026-03-22

Approach:
Use Floyd's Tortoise and Hare algorithm to detect a cycle by moving two pointers at different speeds.
If they meet, a cycle exists; then reset one pointer to the head and move both one step at a time.
Their next meeting point is the entry node of the cycle, derived from the distance relationships in the cycle.

Time Complexity: O(n)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Determine whether a cycle exists.
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) { // Meeting point inside the cycle.
                // Phase 2: Find the entry to the cycle.
                ListNode* p1 = head;
                ListNode* p2 = slow;
                while (p1 != p2) {
                    p1 = p1->next;
                    p2 = p2->next;
                }
                return p1; // Cycle entry.
            }
        }
        return nullptr; // No cycle.
    }
};
```