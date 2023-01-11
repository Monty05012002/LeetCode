//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++){
            mp[arr[i]]++;
        }
        long long int ans=0;
        for(int i=1;i<=N;i++){
            if(mp[arr[i]]>=2){
                mp[arr[i]]--;
                while(mp.find(arr[i])!=mp.end()){
                    arr[i]++;
                    ans++;
                }
                mp[arr[i]]++;
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
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends