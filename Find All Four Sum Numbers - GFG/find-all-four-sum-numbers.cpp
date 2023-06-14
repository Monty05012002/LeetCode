//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(),arr.end());
          vector<vector<int> >ans;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                int beg=j+1,end=arr.size()-1;
                long long val=k-arr[i]-arr[j];
                while(beg<end){
                    long long temp=arr[beg]+arr[end];
                    if(val==temp){
                        ans.push_back({arr[i],arr[j],arr[beg],arr[end]});
                        while(beg<end && arr[beg]==arr[beg+1])
                        beg++;
                        while(beg<end && arr[end]==arr[end-1])
                        end--;
                        
                        beg++;
                        end--;
                    }
                    else if(temp>val)
                    end--;
                    else
                    beg++;
                }
                while(j+1<arr.size() && arr[j]==arr[j+1])
                j++;
            }
            while(i+1<arr.size() && arr[i]==arr[i+1])
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends