```cpp
/*
Problem: Reverse Linked List
Problem Number: 206
Difficulty: Easy
Topic: linked-list
Date: 2026-03-15

Approach:
Iteratively reverse the list by walking through nodes once and rewiring pointers.
Maintain three pointers: prev (reversed prefix), cur (current node), and nxt (saved next node).
At each step, point cur->next to prev, then advance prev and cur; finally prev is the new head.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur) {
            ListNode* nxt = cur->next; // save next node
            cur->next = prev;          // reverse link
            prev = cur;                // advance prev
            cur = nxt;                 // advance cur
        }
        return prev; // new head
    }
};
```