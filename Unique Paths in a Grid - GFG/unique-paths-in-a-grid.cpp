//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
     int mod=1e9+7;
     int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&t){
       if(i>=0 && j>=0 && grid[i][j]==0)
        return 0;
        if(i==0&&j==0)
        return 1;
        if(i<0 || j<0  )
        return 0;
        if(t[i][j]!=-1)
        return t[i][j];
        int up=solve(i-1,j,grid,t);
        int left=solve(i,j-1,grid,t);
        return t[i][j]=(up+left)%mod;
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        
        vector<vector<int>>t(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,t);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends