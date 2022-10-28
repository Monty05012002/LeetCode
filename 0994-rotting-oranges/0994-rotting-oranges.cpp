class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        int cntfre=0,count=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                else
                vis[i][j]=0;
                if(grid[i][j]==1)
                cntfre++;
            }
        }
        int ti=0;
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            ti=max(t,ti);
                q.pop();
            for(int i=0;i<4;i++){
                int newr=r+delRow[i];
                int newc=c+delCol[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]==0 && grid[newr][newc]==1){
                    q.push({{newr,newc},t+1});
                    vis[newr][newc]=2;
                    count++;
                }
            }
        }
        if(count!=cntfre)
        return -1;
        return ti;
    }
};