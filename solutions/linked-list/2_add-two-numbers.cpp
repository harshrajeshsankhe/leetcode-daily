```cpp
/*
Problem: Add Two Numbers
Problem Number: 2
Difficulty: Medium
Topic: linked-list
Date: 2026-03-13

Approach:
Traverse both linked lists simultaneously, adding corresponding digits along with a carry.
Create the result list on the fly using a dummy head, appending a new node for each computed digit.
Continue until both lists are exhausted and no carry remains.

Time Complexity: O(n + m)
Space Complexity: O(1) auxiliary (excluding the output list)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};
```