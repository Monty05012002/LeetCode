class Solution {
public:
     void dfs(int node,vector<int> adjls[], int vis[]){
        vis[node]=1;
        for(auto it:adjls[node]){
            if(!vis[it]){
                dfs(it,adjls,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
       // cout<<V;
        vector<int>adjls[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        int vis[200]={0};
        int cnt=0;
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
        
    }
};