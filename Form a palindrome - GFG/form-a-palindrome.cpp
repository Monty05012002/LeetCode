//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int solve(int i,int j,string &str,vector<vector<int>>&t){
        if(i>=j) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(str[i]==str[j]) return t[i][j]=solve(i+1,j-1,str,t);
        return t[i][j]=1+min(solve(i,j-1,str,t),solve(i+1,j,str,t));
    }
    int countMin(string str){
    //complete the function here
        int n=str.size();
        vector<vector<int>>t(n,vector<int>(n,-1));
        return solve(0,n-1,str,t);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends