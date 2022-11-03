//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>minh;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        minh.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!minh.empty()){
            auto it=minh.top();
            minh.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1)
            return dis;
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int neff=max(abs(heights[row][col]-heights[newr][newc]),dis);
                    if(neff<dist[newr][newc]){
                        dist[newr][newc]=neff;
                        minh.push({neff,{newr,newc}});
                    }
                }
            }
        }
        return 0;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends