//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        // code here
        unordered_map<char,int>mp;
        int maxi=INT_MIN;
        for(auto it:tasks){
            mp[it]++;
            maxi=max(mp[it],maxi);
        }
        int count=0;
        for(auto it:mp){
            if(it.second==maxi)
            count++;
        }
        return max(N,(maxi+(maxi-1)*K+count-1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends