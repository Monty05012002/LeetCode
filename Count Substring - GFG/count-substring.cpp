//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string s,int k){
        unordered_map<char,int>mp;
        int i=0,j=0,ans=0;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            ans+=j-i;
            j++;
        }
        return ans;
    }
    int countSubstring(string s) {
        // Code here
        return solve(s,3)-solve(s,2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends