//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		     string s=str;
		    int n=s.size();
		    int t[n+1][n+1];
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=n;j++){
		            if(i==0||j==0)
		            t[i][j]=0;
		        }
		    }
		    for(int i=1;i<=n;i++){
		        for(int j=1;j<=n;j++){
		            if(i!=j && s[i-1]==str[j-1])
		            t[i][j]=1+t[i-1][j-1];
		            else
		            t[i][j]=max(t[i][j-1],t[i-1][j]);
		        }
		    }
		    return t[n][n];
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends