//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<vector<int>>q;
        q.push({0,0,0,k});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it[0]<0 || it[0]>=n || it[1]<0 || it[1]>=m) 
            continue;
            if(it[0]==n-1 && it[1]==m-1) return it[2];
            if(mat[it[0]][it[1]]==1){
                if(it[3]>0)
                it[3]--;
                else
                continue;
            }
            if(vis[it[0]][it[1]]!=-1 && vis[it[0]][it[1]]>=it[3])
            continue;
            vis[it[0]][it[1]]=it[3];
            q.push({it[0],it[1]-1,it[2]+1,it[3]});
            q.push({it[0],it[1]+1,it[2]+1,it[3]});
            q.push({it[0]-1,it[1],it[2]+1,it[3]});
            q.push({it[0]+1,it[1],it[2]+1,it[3]});
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends