//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	   vector<int>arr(nums.begin(),nums.end());
	   sort(nums.begin(),nums.end());
	   unordered_map<int,int>mp;
	   for(int i=0;i<nums.size();i++){
	       mp[arr[i]]=i;
	   }
	   int count=0;
	   int i=0;
	   while(i<nums.size()){
	       if(mp[nums[i]]==i){
	           i++;
	       }
	       else{
	           swap(nums[i],nums[mp[nums[i]]]);
	           count++;
	       }
	   }
	   return count;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends