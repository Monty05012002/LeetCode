//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
       int maxi=0;
       int i=0,j=0,cntZero=0;
       while(j<n){
           if(nums[j]==0) cntZero++;
           while(i<n && cntZero>k){
               if(nums[i]==0) cntZero--;
               i++;
           }
           maxi=max(j-i+1,maxi);
           j++;
       }
       return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends