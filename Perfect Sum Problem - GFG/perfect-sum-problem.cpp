//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int solve(int ind,int arr[],int n,int sum,vector<vector<int>>&t){
	    if(ind==n){
	        if(sum==0)return 1;
	        return 0;
	    }
	    if(t[ind][sum]!=-1) return t[ind][sum];
	    int pick=0;
	    if(sum>=arr[ind]){
	       pick= solve(ind+1,arr,n,sum-arr[ind],t);
	    }
	    int notpick=solve(ind+1,arr,n,sum,t);
	    return t[ind][sum]=(pick%mod+notpick%mod)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>t(n,vector<int>(sum+1,-1));
        return solve(0,arr,n,sum,t);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends