//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int ans=0;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1){
                    int count=0;
                    if(i!=0 && matrix[i-1][j]==0){
                        count++;
                    }
                    if(i!=0 && j!=0 && matrix[i-1][j-1]==0){
                        count++;
                    }
                    if(i!=0 && j!=m-1 && matrix[i-1][j+1]==0){
                        count++;
                    }
                    if(i!=n-1 && matrix[i+1][j]==0){
                        count++;
                    }
                    if(i!=n-1 && j!=0 && matrix[i+1][j-1]==0){
                        count++;
                    }
                    if(i!=n-1 && j!=m-1 && matrix[i+1][j+1]==0){
                        count++;
                    }
                     if(j!=0 and matrix[i][j-1]==0)
                    {
                        count++;

                    }
                    if(j!=m-1 and matrix[i][j+1]==0)
                    {

                        count++;

                    }
                     if(count%2==0 and count>0)
                    {

                        ans++;

                    }
                    
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
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends