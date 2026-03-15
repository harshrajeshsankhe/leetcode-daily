```cpp
/*
Problem: Intersection of Two Linked Lists
Problem Number: 160
Difficulty: Easy
Topic: linked-list
Date: 2026-03-15

Approach:
Use two pointers starting at the heads of the two lists. Advance each pointer one step at a time; when a pointer reaches the end of its list, redirect it to the head of the other list. After at most (lenA + lenB) steps, the pointers will either meet at the intersection node (same reference) or both become nullptr if no intersection exists.

Time Complexity: O(lenA + lenB)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If either list is empty, no intersection is possible.
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        // After switching heads, both pointers traverse equal total distance.
        // They meet at the intersection node or at nullptr if no intersection.
        while (a != b) {
            a = (a ? a->next : headB);
            b = (b ? b->next : headA);
        }
        return a; // Intersection node or nullptr.
    }
};
```