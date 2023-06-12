//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    // code here
	     priority_queue<int,vector<int>,greater<int>>minh;
	    for(int i=0;i<n;i++){
	        minh.push(arr[i]);
	        if(minh.size()>k){
	            minh.pop();
	        }
	    }
	    vector<int>ans;
	    while(!minh.empty()){
	        ans.push_back(minh.top());
	        minh.pop();
	    }
	    reverse(ans.begin(),ans.end());
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends