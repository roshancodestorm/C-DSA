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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            ListNode* prev = &dummy;

            // Find the correct position
            while (prev->next != nullptr && prev->next->val <= curr->val) {
                prev = prev->next;
            }

            // Insert curr into the sorted list
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        return dummy.next;
    }
};