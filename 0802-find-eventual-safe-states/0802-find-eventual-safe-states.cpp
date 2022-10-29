class Solution {
public:
     bool dfs(int start,vector<vector<int>>& graph,vector<bool>&vis,vector<bool> &pathVis,vector<bool> &check){
        vis[start]=1;
        pathVis[start]=1;
         check[start]=0;
        for(auto it:graph[start]){
            if(vis[it]==0){
               if(dfs(it,graph,vis,pathVis,check)==true)
               return true;
            }
            else if(pathVis[it]==1)
            return true;
        }
        check[start]=1;
        pathVis[start]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
       vector<bool> vis(v, false);
	vector<bool> pathVis(v, false);
	vector<bool> check(v, true);
        vector<int>ans;
        for(int i=0;i<v;i++){
            if(vis[i]==0){
                dfs(i,graph,vis,pathVis,check);
            }
        }
        for(int i=0;i<v;i++){
            if(check[i]==1)
            ans.push_back(i);
        }
        return ans;
    }
};