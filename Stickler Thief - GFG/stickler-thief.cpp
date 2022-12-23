//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>t(n,0);
        
        t[0]=arr[0];
        for(int ind=1;ind<n;ind++){
              int take=arr[ind];
              if(ind>1)
              take+=t[ind-2];
              int nontake=t[ind-1];
              t[ind]=max(take,nontake);
              
        }
        return t[n-1];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends