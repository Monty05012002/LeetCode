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
        if(X==0 && Y==0) return 0;
        queue<pair<int,int>>q;
        vector<vector<int>>vis(N,vector<int>(M,0));
        q.push({0,0});
        vis[0][0]=1;
        int steps=0;
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if(row==X && col==Y) return steps;
                for(int i=0;i<4;i++){
                    int newr=row+dx[i];
                    int newc=col+dy[i];
                    if(newr>=0 && newr<N && newc>=0 && newc<M && !vis[newr][newc] && A[newr][newc]==1){
                        vis[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
            steps++;
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