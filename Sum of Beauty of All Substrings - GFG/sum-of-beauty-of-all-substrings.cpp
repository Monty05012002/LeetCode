//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int beautySum(string s) {
        // Your code goes here
         int ans=0;
        for(int i=0;i<s.size();i++){
            int t[26]={};
            for(int j=i;j<s.size();j++){
                 
                t[s[j]-'a']++;
                int mini=INT_MAX,maxi=0;
                for(int k=0;k<26;k++){
                    if(t[k]>maxi)
                    maxi=t[k];
                    if(t[k]<mini && t[k]!=0)
                    mini=t[k];
                    
                }
                if(mini!=INT_MAX)
                 ans+=maxi-mini;
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.beautySum(s) << endl;
    }
    return 0;
}
// } Driver Code Ends