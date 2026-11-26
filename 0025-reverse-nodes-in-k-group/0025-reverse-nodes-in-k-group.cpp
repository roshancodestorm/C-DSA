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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while(true) {
            ListNode* kth = prevGroup;

            // Find the kth node
            for(int i = 0; i < k; i++) {
                kth = kth->next;
                if(kth == NULL) return dummy.next;
            }

            ListNode* nextGroup = kth->next;

            // Reverse the current group
            ListNode* prev = nextGroup;
            ListNode* curr = prevGroup->next;

            while(curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect reversed group
            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }

        return dummy.next;
    }
};