//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void solve(int node,vector<pair<int,int>>adj[],stack<int>&s,vector<int>&vis){
         vis[node]=1;
         for(auto it:adj[node]){
             if(!vis[it.first]){
                 solve(it.first,adj,s,vis);
             }
         }
         s.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<int>vis(N,0);
        vector<pair<int,int>>adj[N];
        vector<int>dist(N,1e9);
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            adj[u].push_back({edges[i][1],edges[i][2]});
        }
        stack<int>s;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                solve(i,adj,s,vis);
            }
        }
        dist[0]=0;
        while(!s.empty()){
            auto t=s.top();
            s.pop();
            for(auto it:adj[t]){
                int v=it.first;
                int wt=it.second;
                if(dist[t]+wt<dist[v]){
                    dist[v]=dist[t]+wt;
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends