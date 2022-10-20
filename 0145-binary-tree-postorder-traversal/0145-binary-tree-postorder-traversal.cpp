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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>s1;
        TreeNode*curr=root;
        vector<int>ans;
        while(curr!=NULL || !s1.empty()){
            if(curr!=NULL){
                s1.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode*temp=s1.top()->right;
                if(temp==NULL){
                    temp=s1.top();
                    s1.pop();
                    ans.push_back(temp->val);
                    while(!s1.empty()&&temp==s1.top()->right){
                        temp=s1.top();
                        s1.pop();
                        ans.push_back(temp->val);
                    }
                
                }
                else
                    curr=temp;
            }
        }
        return ans;
    }
};