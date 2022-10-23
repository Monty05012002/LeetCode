/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode*parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(temp->left){
                parent_track[temp->left]=temp;
                q.push(temp->left);
            }
            if(temp->right){
                parent_track[temp->right]=temp;
                q.push(temp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>p;
        markParents(root,p,target);
        unordered_map<TreeNode*,bool>v;
        queue<TreeNode*>q;
        q.push(target);
        v[target]=true;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            if(level++==k)
                break;
            for(int i=0;i<size;i++){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left && !v[curr->left]){
                    q.push(curr->left);
                    v[curr->left]=true;
                }
                if(curr->right && !v[curr->right]){
                    q.push(curr->right);
                    v[curr->right]=true;
                }
                if(p[curr] &&!v[p[curr]]){
                    q.push(p[curr]);
                    v[p[curr]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};