//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
       vector<pair<int,int>>s;
       for(int i=0;i<N;i++){
           if(s.empty()) {
               s.push_back({color[i],radius[i]});
           }
           else{
               if(color[i]==s.back().first && radius[i]==s.back().second){
                   s.pop_back();
               }
               else{
                   s.push_back({color[i],radius[i]});
               }
           }
       }
       return s.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends