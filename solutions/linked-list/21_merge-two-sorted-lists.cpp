```cpp
/*
Problem: Merge Two Sorted Lists
Problem Number: 21
Difficulty: Easy
Topic: linked-list
Date: 2026-03-15

Approach:
Use an iterative merge with a dummy head pointer to build the result list in-place without allocating new nodes.
At each step, attach the smaller head node from the two lists to the merged tail and advance that list.
When one list is exhausted, append the remaining nodes from the other list.

Time Complexity: O(n + m)
Space Complexity: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Dummy head simplifies edge cases (empty result, attaching first node, etc.)
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Merge by always taking the smaller current node.
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

        // Append any remaining nodes (at most one list is non-null).
        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }
};
```