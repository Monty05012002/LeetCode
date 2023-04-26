//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	    int mod=1e9+7;
	    int solve(int ind,string &s,vector<int>&t){
        if(ind<s.size() && s[ind]=='0') return 0;
        if(ind>=s.size()) return 1;
        if(t[ind]!=-1) return t[ind];
        int ans=0;
        if(s[ind]!='0')
        ans=solve(ind+1,s,t)%mod;
      if(ind+1 < s.size() && ((s[ind] == '1' && s[ind+1] <= '9') || (s[ind]=='2' && s[ind+1] < '7')))
           ans += solve( ind+2, s,t)%mod;
        return t[ind]= ans%mod;
    }
		int CountWays(string s){
		    // Code here
		    vector<int>t(s.size(),-1);
		    return solve(0,s,t);
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends