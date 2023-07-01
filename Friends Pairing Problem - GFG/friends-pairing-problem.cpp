//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    long long mod=1e9+7;
    long long solve(int n,vector<int>&t){
        if(n==1 || n==2)
        return n;
        if(t[n]!=-1)
        return t[n];
        return t[n]=(solve(n-1,t)+(1LL*n-1)*solve(n-2,t))%mod;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<int>t(n+1,-1);
        return solve(n,t);
    }
};    
 

//{ Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends