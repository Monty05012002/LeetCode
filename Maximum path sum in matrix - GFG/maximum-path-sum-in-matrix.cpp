//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(vector<vector<int>> &Matrix,int i,int j,int N,vector<vector<int>>&t){
        if(j<0 || j>=N ) return 0;
        if(i==0) return Matrix[0][j];
        if(t[i][j]!=-1) return t[i][j];
        int u=Matrix[i][j]+solve(Matrix,i-1,j,N,t);
        int ld=Matrix[i][j]+solve(Matrix,i-1,j-1,N,t);
        int rd=Matrix[i][j]+solve(Matrix,i-1,j+1,N,t);
        return t[i][j]=max(u,max(ld,rd));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int maxi=INT_MIN;
        vector<vector<int>>t(N,vector<int>(N,-1));
        for(int j=0;j<N;j++){
            maxi=max(maxi,solve(Matrix,N-1,j,N,t));
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends