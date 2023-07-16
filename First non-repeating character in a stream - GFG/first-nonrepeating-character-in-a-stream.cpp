//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int>mp(26,0);
		    string ans="";
		    int j=0;
		    for(int i=0;i<A.size();i++){
		        mp[A[i]-'a']++;
		        if(mp[A[j]-'a']==1) ans+=A[j];
		        else{
		            while(j<=i && mp[A[j]-'a']!=1){
		                j++;
		            }
		            if(j>i)ans+='#';
		            else ans+=A[j];
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends