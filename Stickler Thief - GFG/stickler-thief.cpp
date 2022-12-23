//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int solve(int ind,int arr[],vector<int>&t){
        if(ind==0) return arr[0];
        if(ind<0) return 0;
        if(t[ind]!=-1) return t[ind];
        int take=arr[ind]+solve(ind-2,arr,t);
        int nontake=solve(ind-1,arr,t);
        return t[ind]=max(take,nontake);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>t(n,-1);
        return solve(n-1,arr,t);
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