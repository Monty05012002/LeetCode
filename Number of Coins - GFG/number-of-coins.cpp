//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(int arr[], int n, int sum) 
	{ 
	    // Your code goes here
	    int dp[n+1][sum+1] ; 
	    for(int i=0 ; i<=n ; i++){
	        dp[i][0]=0 ; 
	    }
	    for(int i=1 ; i<=sum ; i++){
	        dp[0][i]=sum+100 ; 
	    }
	    for(int i=1 ; i<=n ; i++){
	        for(int j=1 ; j<=sum ; j++){
	            if(arr[i-1]<=j){
	                dp[i][j] = min(dp[i][j-arr[i-1]]+1,dp[i-1][j]) ;
	            }
	            else{
	                dp[i][j] = dp[i-1][j] ;
	            }
	        }
	    }
	    return dp[n][sum]==sum+100?-1:dp[n][sum] ;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends