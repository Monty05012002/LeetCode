//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1e9+7;
    int solve(int n,int r,vector<vector<int>>&t){
        if(r>n) return 0;
        if(n==r || r==0) return 1;
        if(t[n][r]!=-1) return t[n][r];
        return t[n][r]=(solve(n-1,r,t)+solve(n-1,r-1,t))%mod;
    }
    int nCr(int n, int r){
        // code here
        vector<vector<int>>t(n+1,vector<int>(r+1,-1));
        return solve(n,r,t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends