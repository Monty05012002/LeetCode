//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &m,int n,vector<string>&ans,vector<vector<int>>&vis,string s){
        if(i==n-1 && j==n-1){
            ans.push_back(s);
            return;
        }
       int di[]={1,0,0,-1};
       int dj[]={0,-1,1,0};
       string str="DLRU";
       for(int k=0;k<4;k++){
           int nr=i+di[k];
           int nc=j+dj[k];
           if(nr>=0 && nc>=0 && nc<n && nr<n && !vis[nr][nc] && m[nr][nc]==1){
            vis[i][j]=1;
            solve(nr,nc,m,n,ans,vis,s+str[k]);
            vis[i][j]=0;
        }
       }
        
         
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>ans;
        if(m[0][0]==1) solve(0,0,m,n,ans,vis,"");
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends