//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        if(n==1 || n==2)
        return n;
        if(n==3) return n+1;
        long long a=1,b=2,c=4,d;
        long long mod=1000000007;
        for(int i=4;i<=n;i++){
            d=(a+b+c)%mod;
            a=b;
            b=c;
            c=d;
        }
        return d%mod;
        
        
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends