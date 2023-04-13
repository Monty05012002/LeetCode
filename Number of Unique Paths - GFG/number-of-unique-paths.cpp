//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int solve(int i,int j,vector<vector<int>>&t){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0 ) return 0;
        if(t[i][j]!=-1) return t[i][j];
        int left=solve(i,j-1,t);
        int up=solve(i-1,j,t);
        return t[i][j]=left+up;
        
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>t(a,vector<int>(b,-1));
        return solve(a-1,b-1,t);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends