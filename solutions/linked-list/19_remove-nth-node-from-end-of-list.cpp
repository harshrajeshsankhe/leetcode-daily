```cpp
/*
Problem: Remove Nth Node From End of List
Problem Number: 19
Difficulty: Medium
Topic: linked-list
Date: 2026-03-13

Approach:
Use a dummy head and two pointers. Advance the fast pointer n steps ahead, then move both fast and slow together until fast reaches the end; slow will then point to the node before the one to remove. Relink slow->next to skip the target node and return dummy.next.

Time Complexity: O(L)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles edge cases like removing the head.
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast pointer n steps ahead.
        for (int i = 0; i < n; ++i) fast = fast->next;

        // Move both pointers until fast is at the last node.
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from end (slow->next).
        ListNode* toDelete = slow->next;
        slow->next = toDelete->next;

        // In LeetCode, freeing is optional but safe.
        delete toDelete;

        return dummy.next;
    }
};
```