//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


    
    //Function to find a Mother Vertex in the Graph.
  class Solution 
{
    public:
    void dfs(int node,vector<int>adj[], vector<int>&vis,set<int>&s){
        vis[node]=1;
        s.insert(node);
        for(auto it:adj[node]) if(s.find(it) == s.end()) dfs(it,adj,vis,s);
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++){
	        set<int>s;
	        if(!vis[i]) dfs(i,adj,vis,s);
	        if(s.size()==V) return i;
	    }
	    return -1;
	}

};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends