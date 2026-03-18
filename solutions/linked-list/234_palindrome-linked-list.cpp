```cpp
/*
Problem: Palindrome Linked List
Problem Number: 234
Difficulty: Easy
Topic: linked-list
Date: 2026-03-18

Approach:
Use fast/slow pointers to find the middle of the list, then reverse the second half in-place.
Compare nodes from the start and from the reversed second half to check for palindrome equality.
Finally, reverse the second half again to restore the original list structure.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // 1) Find middle (slow) using fast/slow pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // If fast is not null, length is odd; skip the middle element
        if (fast) slow = slow->next;

        // 2) Reverse second half
        ListNode* second = reverseList(slow);

        // 3) Compare first half with reversed second half
        bool ok = true;
        ListNode* p1 = head;
        ListNode* p2 = second;
        while (p2) { // only need to traverse the second half
            if (p1->val != p2->val) {
                ok = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // 4) Restore list (optional but good practice)
        reverseList(second);

        return ok;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
};
```