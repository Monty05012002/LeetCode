//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long mod=1e9+7;
    long long solve(long long n,vector<long long>&t){
        if(n<0) return 0;
        if(n==0) return 1;
        if(t[n]!=-1) return t[n];
        return t[n]=(solve(n-1,t)+solve(n-2,t)+solve(n-3,t))%mod;
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<long long>t(n+1,-1);
        return solve(n,t);
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends