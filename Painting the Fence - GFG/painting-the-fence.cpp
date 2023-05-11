//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long mod=1e9+7;
    long long solve(int n,int k,vector<long long>&t){
        if(n==1) 
        return k;
        if(n==2) 
        return k*k;
        if(t[n]!=-1) return t[n];
        long long take=(solve(n-2,k,t)*(k-1))%mod;
        long long nontake=(solve(n-1,k,t)*(k-1))%mod;
        return t[n]=(take+nontake)%mod;
    }
    long long countWays(int n, int k){
        // code here
        vector<long long>t(10005,-1);
        return solve(n,k,t);
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends