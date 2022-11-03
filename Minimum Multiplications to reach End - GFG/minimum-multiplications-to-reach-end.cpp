//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        vector<int>dist(100000,1e9);
        q.push({start,0});
        dist[start]=0;
        int mod=100000;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int steps=it.second;
            int node=it.first;
            for(auto i:arr){
                int nev=(i*node)%mod;
                if(steps+1<dist[nev]){
                    dist[nev]=steps+1;
                    if(nev==end)
                    return steps+1;
                    q.push({nev,steps+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends