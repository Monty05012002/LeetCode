//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
      
     bool solve(int i,int j,vector<vector<char>>& board,string &word,vector<vector<int>>&vis,int p){
        if(p==word.size()) return true;
        int n=board.size();
        int m=board[0].size();
          int dr[]={0,0,-1,1};
          int dc[]={-1,1,0,0};
        vis[i][j]=1;
         for(int k=0;k<4;k++){
             int nr=i+dr[k];
             int nc=j+dc[k];
             if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && word[p]==board[nr][nc]){
                 if(solve(nr,nc,board,word,vis,p+1)) return true;
             }
         }
          vis[i][j]=0;
         return false;


    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
       vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,board,word,vis,1)) return true;
                }
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends