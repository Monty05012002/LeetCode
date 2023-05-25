//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long mod=1e9+7;
    long long solve(int n,int x,int ind,vector<vector<long long>>&t){
        if(n==0) return 1;
        if(ind>n) return 0;
        if(t[n][ind]!=-1) return t[n][ind];
        long long val=pow(ind,x);
        if(val<=n){
            return t[n][ind]=(solve(n-val,x,ind+1,t)+solve(n,x,ind+1,t))%mod;
        }else{
            return t[n][ind]=0;
        }
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<long long>>t(n+1,vector<long long>(n+1,-1));
        return solve(n,x,1,t);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends