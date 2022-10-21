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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            TreeNode *temp=top.first;
            int a=top.second.first;
            int b=top.second.second;
            mp[a][b].insert(temp->val);
            if(temp->left){
                q.push({temp->left,{a-1,b+1}});
            }
            if(temp->right){
                q.push({temp->right,{a+1,b+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto it:mp){
            vector<int>v;
            for(auto i:it.second){
                v.insert(v.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};