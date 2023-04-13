//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int ind,int *arr,int n,vector<int>&t){
	    if(ind<0) return 0;
	    if(ind==0) return arr[0];
	    if(t[ind]!=-1) return t[ind];
	    int take=arr[ind]+solve(ind-2,arr,n,t);
	    int nontake=solve(ind-1,arr,n,t);
	    return t[ind]=max(take,nontake);
	    
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int>t(n+1,-1);
	    return solve(n-1,arr,n,t);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends