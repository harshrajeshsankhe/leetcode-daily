```cpp
/*
Problem: Merge k Sorted Lists
Problem Number: 23
Difficulty: Hard
Topic: linked-list
Date: 2026-03-15

Approach:
Use a min-heap (priority_queue with custom comparator) containing the current head of each non-empty list.
Repeatedly extract the smallest node, append it to the merged list, and push its next node into the heap.
This always selects the global minimum available node and reuses existing nodes without extra allocations.

Time Complexity: O(N log k) where N is the total number of nodes across all lists
Space Complexity: O(k) for the heap
*/

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        struct Cmp {
            bool operator()(const ListNode* a, const ListNode* b) const {
                return a->val > b->val; // min-heap behavior
            }
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, Cmp> pq;
        for (ListNode* head : lists) {
            if (head) pq.push(head);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            // Append node to result
            tail->next = node;
            tail = node;

            // Push next node from the same list (if any)
            if (node->next) pq.push(node->next);
        }

        // Ensure the merged list is properly terminated
        tail->next = nullptr;
        return dummy.next;
    }
};
```