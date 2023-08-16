//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        vector<long long>t(n+1,0);
        t[0]=1;
        t[1]=1;
        int mod=1e9+7;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                t[i]=(t[i]+(t[j]*t[i-j-1])%mod)%mod;
            }
        }
        return t[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends