//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        // code here
        priority_queue<int,vector<int>,greater<int>>minh;
        for(int i=0;i<n;i++){
            minh.push(arr[i]);
        }
        int count=0;
        while(minh.size()>1 && minh.top()<k){
            int top=minh.top();
            minh.pop();
            int top1=minh.top();
            minh.pop();
            minh.push(top+top1);
            count++;
        }
        if(minh.top()<k) return -1;
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        int ans = obj.minOperations(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends