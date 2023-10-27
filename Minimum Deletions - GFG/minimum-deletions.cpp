//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        int n=S.size();
        string temp=S;
        reverse(temp.begin(),temp.end());
        int t[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0||j==0) t[i][j]=0;
            }
        }
        int mod=1e9+7;
         for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                 if(S[i-1]==temp[j-1]) t[i][j]=1+t[i-1][j-1];
                 else t[i][j]=max(t[i-1][j],t[i][j-1]);
                 t[i][j]%=mod;
             }
         }
        return n-t[n][n];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends