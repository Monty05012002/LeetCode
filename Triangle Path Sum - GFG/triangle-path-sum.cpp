//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int i,int j,int n,vector<vector<int>>&triangle,vector<vector<int>>&t){
        if(i==n-1) return triangle[n-1][j];
        if(t[i][j]!=-1) return t[i][j];
        int down =triangle[i][j]+solve(i+1,j,n,triangle,t);
        int diag =triangle[i][j]+solve(i+1,j+1,n,triangle,t);
        return t[i][j]=min(down,diag);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        vector<vector<int>>t(n,vector<int>(n+1,-1));
        return solve(0,0,n,triangle,t);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends