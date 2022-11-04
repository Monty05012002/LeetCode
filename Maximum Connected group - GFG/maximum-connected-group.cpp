//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
public:
    vector<int> size,parent;
    
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    
    int findUPar(int node){
        if(parent[node] == node)return node;
        
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return; 
        
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
        
    }
};
class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
         int n = grid.size();
        int maxi = 0, dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
        
        DisjointSet dsu(n*n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    int r = i, c = j;
                    
                    for(int k=0;k<4;k++){
                        int newx = r+dx[k];
                        int newy = c+dy[k];
                        
                        if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]){
                            dsu.unionBySize(newx*n+newy,r*n+c);
                        }
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int>st;
                    int res = 0, r = i, c = j;;
                    
                    for(int k=0;k<4;k++){
                        int newx = r+dx[k];
                        int newy = c+dy[k];
                        
                        if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]){
                            st.insert(dsu.findUPar(newx*n+newy));
                        }
                    }
                    
                    for(auto it:st){
                        res+=dsu.size[it];
                    }
                    maxi = max(maxi,res+1);
                }
            }
        }
        
  //For checking all ones
       
        for(int i=0;i<=n*n;i++)maxi = max(maxi,dsu.size[dsu.findUPar(i)]);
    
        return maxi;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends