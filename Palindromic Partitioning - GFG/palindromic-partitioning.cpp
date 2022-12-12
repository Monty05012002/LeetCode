//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(string s,int i,int j,vector<vector<int>>&t){
        if(i>=j)
        return 0;
        if(isPalindrome(s,i,j)==true)
        return 0;
        if(t[i][j]!=-1)
        return t[i][j];
        int ans=INT_MAX,left,right;
        for(int k=i;k<j;k++){
            if(t[i][k]!=-1)
            left=t[i][k];
            else{
                left=solve(s,i,k,t);
                t[i][k]=left;
            }
            if(t[k+1][j]!=-1){
                right=t[k+1][j];
            }
            else{
                right=solve(s,k+1,j,t);
                t[k+1][j]=right;
            }
            int temp=1+left+right;
            ans=min(ans,temp);
        }
        return t[i][j]=ans;
    }
    bool isPalindrome(string s,int i,int j){
        if(i==j)
        return true;
        if(i>j)
        return true;
        while(i<j){
            if(s[i]!=s[j])
            return false;
            j--;
            i++;
        }
        return true;
    }
    int palindromicPartition(string s)
    {
        // code here
         int n=s.size();
        vector<vector<int>>t(n,vector<int>(n,-1));
        int i=0,j=n-1;
        return solve(s,i,j,t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends