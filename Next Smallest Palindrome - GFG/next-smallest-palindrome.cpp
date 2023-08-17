//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    vector<int>ans(n);
	    int change=1;
	    for(int i=0;i<n;i++) ans[i]=num[i];
	    for(int i=0;i<n/2;i++){
	        if(num[i]>num[n-i-1]) change=0;
	        else if(num[i]<num[n-i-1]) change=1;
	        ans[n-i-1]=ans[i];
	    }
	    int i=n/2;
	    while(change && i<n){
	        if(ans[i]==9){
	            ans[i]=0;
	           ans[n-i-1]=0;
	        }else{
	            ans[i]++;
	            ans[n-i-1]=ans[i];
	            change=0;
	        }
	        i++;
	    }
	    if(change==1){
	        ans[0]=1;
	        ans.push_back(1);
	    }
	    return ans;
	    
	    return ans;
	}

};

//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num[n];
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
        Solution ob;
        auto ans = ob.generateNextPalindrome(num, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends