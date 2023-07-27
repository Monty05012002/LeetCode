//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
            // code here 
            priority_queue<int>maxh;
            unordered_map<int,int>mp1,map2;
            unordered_set<int>s;
            for(int i=0;i<n;i++){
                mp1[arr1[i]]++;
                 mp1[arr2[i]]++;
            }
            for(auto it:mp1) maxh.push(it.first);
            vector<int>ans;
            int k=n;
            while(k--){
                int top=map2[maxh.top()]++;
                maxh.pop();
            }
            for(int i=0;i<n;i++){
                if(map2[arr2[i]]!=0){
                    ans.push_back(arr2[i]);
                    map2[arr2[i]]=0;
                }
            }
            for(int i=0;i<n;i++){
                if(map2[arr1[i]]!=0){
                    ans.push_back(arr1[i]);
                    map2[arr1[i]]=0;
                }
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends