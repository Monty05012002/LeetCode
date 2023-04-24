//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        vector<vector<int>>t(N,vector<int>(M,0));
        queue<pair<int,int>>q;
        if(A[0][0]==0) return -1;
        q.push({0,0});
        t[0][0]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            ans++;
            while(size--){
              auto it=q.front();
              q.pop();
              int row=it.first;
              int col=it.second;
              if(row==X && col==Y) return ans-1;
              for(int i=0;i<4;i++){
                  int nr=row+dr[i];
                  int nc=col+dc[i];
                  if(nr>=0 && nr<N && nc>=0 && nc<M && A[nr][nc]==1 && t[nr][nc]==0){
                      q.push({nr,nc});
                      t[nr][nc]=1;
                  }
              }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends