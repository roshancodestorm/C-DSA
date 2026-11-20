/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;

        // Step 1: Create all cloned nodes
        Node* temp = head;

        while (temp != NULL) {
            mp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        // Step 2: Connect next and random pointers
        temp = head;

        while (temp != NULL) {
            mp[temp]->next = (temp->next != NULL) ? mp[temp->next] : NULL;
            mp[temp]->random = (temp->random != NULL) ? mp[temp->random] : NULL;

            temp = temp->next;
        }

        return mp[head];
    }
};