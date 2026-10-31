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
    vector<TreeNode*> generate(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> ans;

        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generate(start, i - 1);
            vector<TreeNode*> right = generate(i + 1, end);

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};
