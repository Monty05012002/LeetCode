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
    bool isSymmetric(TreeNode* root) {
        return root==NULL || isSymmetrichelp(root->left,root->right);
    }
    bool isSymmetrichelp(TreeNode* node,TreeNode* node1){
        if(node==NULL||node1==NULL)
            return node==node1;
        if(node->val!=node1->val)
            return false;
        return isSymmetrichelp(node->left,node1->right) && isSymmetrichelp(node->right,node1->left);
    }
};