//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    int mod=1e9+7;
	    int n=s.size();
	    vector<long long>t(n+1,0);
	    t[0]=1;
	    vector<int>last(26,-1);
	    for(int i=1;i<=n;i++){
	        t[i]=(2*t[i-1])%mod;
	        if(last[s[i-1]-'a']!=-1){
	            t[i]=t[i]-t[last[s[i-1]-'a']];
	            t[i]=(t[i]+mod)%mod;
	        }
	        last[s[i-1]-'a']=i-1;
	    }
	    return (t[n]+mod)%mod;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends