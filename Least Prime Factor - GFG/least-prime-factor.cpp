//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int>t(n+1);
        for(int i=0;i<=n;i++) t[i]=i;
        for(int i=2;i<=n;i++){
            if(t[i]==i){
                for(int j=2*i;j<=n;j+=i){
                    t[j]=min(t[j],i);
                }
            }
        }
        return t;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends