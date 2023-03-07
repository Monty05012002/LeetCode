//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        // code here
        vector<bool>t(N+1,true);
        t[0]=false;
        t[1]=false;
         for(int i=2;i<=N;i++){
             if(t[i]){
                 for(int j=2*i;j<=N;j+=i){
                     t[j]=false;
                 }
             }
         }
         vector<int>ans;
         for(int i=M;i<=N;i++){
             if(t[i]==true){
                 ans.push_back(i);
             }
         }
         return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}
// } Driver Code Ends