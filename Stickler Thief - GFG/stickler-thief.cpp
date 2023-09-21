//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int ind,int arr[],int n,vector<int>&t){
        if(ind>=n) return 0;
        if(t[ind]!=-1) return t[ind];
        int notpick=solve(ind+1,arr,n,t);
        int pick=arr[ind]+solve(ind+2,arr,n,t);
        return t[ind]=max(pick,notpick);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>t(n+1,-1);
        return solve(0,arr,n,t);
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