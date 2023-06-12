//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:

		int min_operations(vector<int>nums){
		    // Code here
		    int n=nums.size();
		    vector<int>dp(n,1);
		    int maxi=1;
		    for(int i=1;i<n;i++){
		        for(int j=0;j<i;j++){
		            if(nums[j]<nums[i] && 1+dp[j]>dp[i] && (i-j)<=nums[i]-nums[j]){
		                dp[i]=1+dp[j];
		            }
		        }
		        maxi=max(maxi,dp[i]);
		    }
		    return n-maxi;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans  = ob.min_operations(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends