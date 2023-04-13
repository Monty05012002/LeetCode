//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int ind,vector<int>& height,int n,int k,vector<int>&t){
        if(ind==0) return 0;
        int ans=INT_MAX;
        if(t[ind]!=-1) return t[ind];
        for(int j=1;j<=k;j++){
            if(ind-j>=0){
                int temp=abs(height[ind]-height[ind-j])+solve(ind-j,height,n,k,t);
                ans=min(temp,ans);
            }
        }
        return t[ind]=ans;
        
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>t(n+1,-1);
        return solve(n-1,height,n,k,t);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends