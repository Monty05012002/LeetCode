//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet{
    public:
        vector<int>size,parent;
        DisjointSet(int n){
            size.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findUParent(int node){
            if(node==parent[node])return node;
            return parent[node]=findUParent(parent[node]);
        }

        void unionS(int u,int v){
            int up_u=findUParent(u);
            int up_v=findUParent(v);
            if(up_u==up_v)return;
            if(size[up_u]>size[up_v]){
                parent[up_v]=up_u;
                size[up_v]+=size[up_u];
            }
            else{
                parent[up_v]=up_u;
                size[up_u]+=size[up_v];
            }
        }

};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int count=0;
        vector<int>ans;
        for(auto it:operators){
            int row=it[0];
            int col=it[1];
            if(vis[row][col]==1){
                ans.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++;
            int dr[]={-1,0,1,0};
            int dc[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=dc[i]+col;
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    if(vis[newr][newc]==1){
                        int noden=row*m+col;
                        int nwn=newr*m+newc;
                        if(ds.findUParent(noden)!=ds.findUParent(nwn)){
                            count--;
                            ds.unionS(noden,nwn);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends