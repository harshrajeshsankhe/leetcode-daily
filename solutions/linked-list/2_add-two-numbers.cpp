```cpp
/*
Problem: Add Two Numbers
Problem Number: 2
Difficulty: Medium
Topic: linked-list
Date: 2026-03-15

Approach:
Traverse both linked lists simultaneously, adding corresponding digits along with a carry.
Create the resulting list on the fly using a dummy head to simplify pointer handling.
Continue until both lists are exhausted and no carry remains, appending each computed digit as a new node.

Time Complexity: O(max(m, n))
Space Complexity: O(max(m, n))  // for the output list
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