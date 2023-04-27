//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    queue<pair<pair<int,int>,int>>q;
	    q.push({{KnightPos[0],KnightPos[1]},0});
	    vis[KnightPos[0]][KnightPos[1]]=1;
	    int dr[]={+1,+1,-1,-1,-2,-2,+2,+2};
	    int dc[]={+2,-2,+2,-2,+1,-1,-1,+1};
	    while(!q.empty()){
	        auto it=q.front();
	        q.pop();
	        int r=it.first.first;
	        int c=it.first.second;
	        int st=it.second;
	        if(r==TargetPos[0] && c==TargetPos[1]) return st;
	        for(int i=0;i<8;i++){
	            int nr=r+dr[i];
	            int nc=c+dc[i];
	            if(nr>=0 && nr<=N && nc>=0 && nc<=N && vis[nr][nc]==0){
	                q.push({{nr,nc},st+1});
	                vis[nr][nc]=1;
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends