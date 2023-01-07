//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     void solve(int ind,vector<int>&temp,vector<vector<int>>&ans,int k,int n){
        
          if(n==0 && k==0){
              ans.push_back(temp);
              return;
          }
            if(k==0)
          return;
          for(int i=ind;i<=9;i++){
                  temp.push_back(i);
                  solve(i+1,temp,ans,k-1,n-i);
                    temp.pop_back();
          }
          return ;
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<int>temp;
        vector<vector<int>>ans;
        solve(1,temp,ans,K,N);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends