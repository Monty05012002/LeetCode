//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int start,vector<int>adj[],int vis[],int pathvis[]){
        vis[start]=1;
        pathvis[start]=1;
        for(auto it:adj[start]){
            if(vis[it]==0){
               if(dfs(it,adj,vis,pathvis)==true)
               return true;
            }
            else if(pathvis[it]==1)
            return true;
        }
        pathvis[start]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathvis[V]={0};
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                if(dfs(i,adj,vis,pathvis)==true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends