//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
   bool solve(int row, int col,vector<vector<char>>& grid, string word, int nrow[], int ncol[]) {
        int n = grid.size();
        int m = grid[0].size();
        int size = word.size();
        
        for (int a = 0; a < 8; a++) {
            int c = row;
            int d = col;
            int index = 0;
            while (index < size && c >= 0 && c < n && d >= 0 && d < m && grid[c][d] == word[index]) {
                index++;
                c += nrow[a];
                d += ncol[a];
            }
            if (index == size) {
                return true;
            }
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	     int n = grid.size();
        int m = grid[0].size();
        int size = word.size();
        vector<vector<int>> ans;
        int nrow[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int ncol[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==word[0] && solve(i,j,grid,word,nrow,ncol)){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends