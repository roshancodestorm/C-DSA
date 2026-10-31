/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr;
        TreeNode *prev = nullptr, *curr = root;

        while (curr) {
            if (!curr->left) {
                if (prev && prev->val > curr->val) {
                    if (!first) first = prev;
                    second = curr;
                }

                prev = curr;
                curr = curr->right;
            }
            else {
                TreeNode* temp = curr->left;

                while (temp->right && temp->right != curr)
                    temp = temp->right;

                if (!temp->right) {
                    temp->right = curr;
                    curr = curr->left;
                }
                else {
                    temp->right = nullptr;

                    if (prev && prev->val > curr->val) {
                        if (!first) first = prev;
                        second = curr;
                    }

                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        swap(first->val, second->val);
    }
};
