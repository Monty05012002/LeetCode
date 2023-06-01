//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    vector<int>prime;
    void precompute(){
      vector<bool>t(1e6+1,true);
      t[0]=false;
      t[1]=false;
      for(int i=2;i<=1e6;i++){
          if(t[i]){
              prime.push_back(i);
              for(int j=2*i;j<=1e6;j+=i)
              t[j]=false;
          }
      }
    }
    void dfs(int node,vector<vector<int>> &g,int &count,vector<int>&vis){
        vis[node]=1;
        count++;
        for(auto it:g[node]){
            if(!vis[it]){
                dfs(it,g,count,vis);
            }
        }
    }
    int helpSanta(int n, int m, vector<vector<int>> &g){
        // Code here
        vector<int>vis(n+1,0);
        int maxi=1;
        for(int i=1;i<n;i++){
            int count=0;
            if(!vis[i]){
                dfs(i,g,count,vis);
                maxi=max(maxi,count);
            }
        }
        if(maxi==1) return -1;
        return prime[maxi-1];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g(n+10);
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends