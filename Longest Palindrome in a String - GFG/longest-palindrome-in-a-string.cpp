//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        // code here
       int n=s.size();
       vector<vector<bool>>t(n,vector<bool>(n,false));
       int start=0,end=0;
       for(int i=0;i<n;i++){
           t[i][i]=true;
           if(i+1<n && s[i]==s[i+1]){
               t[i][i+1]=true;
               if(2>end-start+1){
                   end=i+1;
                   start=i;
               }
           }
       }
       for(int k=2;k<n;k++){
           for(int i=0;i<n-k;i++){
               int j=i+k;
               if(s[i]==s[j] && t[i+1][j-1]){
                   t[i][j]=true;
                   if(j-i+1>end-start+1){
                       end=j;
                       start=i;
                   }
               }
           }
       }
       return s.substr(start,end-start+1);
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends