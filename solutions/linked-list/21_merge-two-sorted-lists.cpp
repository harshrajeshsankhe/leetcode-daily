```cpp
/*
Problem: Merge Two Sorted Lists
Problem Number: 21
Difficulty: Easy
Topic: linked-list
Date: 2026-03-13

Approach:
Use an iterative two-pointer merge with a dummy head node. Repeatedly link the smaller current node from either list to the merged tail and advance that list pointer. When one list is exhausted, append the remainder of the other list to finish.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy node to simplify edge cases (e.g., empty lists).
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Merge by always taking the smallest head node.
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // Append the remaining nodes (at most one list is non-null).
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};
```