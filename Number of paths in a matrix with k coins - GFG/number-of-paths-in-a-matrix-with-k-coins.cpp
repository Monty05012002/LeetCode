//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    
    long long solve(int i,int j,vector<vector<int>>&arr,int k,int n,vector<vector<vector<long long >>>&t){
        if(i==n-1 && j==n-1){
            if(k-arr[i][j]==0){
                return 1;
            }
            else
            return 0;
        }
        if(i>n-1 || j>n-1){
            return 0;
            
        }
        if(k<0) {
         return 0;
        }
        if(t[k][i][j]!=-1) return t[k][i][j];
        long long bottom=solve(i+1,j,arr,k-arr[i][j],n,t);
        long long right=solve(i,j+1,arr,k-arr[i][j],n,t);
        return t[k][i][j]=bottom+right;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        // Code Here
        vector<vector<vector<long long >>>t(k+1,vector<vector<long long>>(n+1,vector<long long>(n+1,-1)));
        return solve(0,0,arr,k,n,t);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends