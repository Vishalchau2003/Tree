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
    void findtraversal(vector<int>& nums, TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        nums.push_back(root->val);           // Visit the root
        findtraversal(nums, root->left);     // Traverse left subtree
        findtraversal(nums, root->right);    // Traverse right subtree
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        findtraversal(nums, root);
        return nums;
    }
};
