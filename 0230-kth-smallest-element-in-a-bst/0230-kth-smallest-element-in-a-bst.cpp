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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=0;
        while(root!=NULL){
            if(root->left==NULL){
                count++;
                if(count==k)
                    ans=root->val;
               root=root->right;
            }
            else{
                TreeNode*prev=root->left;
                while(prev->right&&prev->right!=root)
                    prev=prev->right;
                if(prev->right==NULL){
                    prev->right=root;
                    root=root->left;
                }
                else{
                    prev->right=NULL;
                    count++;
                    if(count==k)
                        ans=root->val;
                    root=root->right;
                }
            }
        }
        return ans;
    }
};