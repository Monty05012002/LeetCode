//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPrimes(int L, int R) {
        // code here
        vector<bool>t(R+1,true);
        t[0]=t[1]=false;
        for(int i=2;i*i<=R;i++){
            if(t[i]){
            for(int j=2*i;j<=R;j+=i){
                t[j]=false;
            }
                
            }
        }
        int count=0;
        for(int i=L;i<=R;i++){
            if(t[i]==true){
                count++;
            }
        }
        return count;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}
// } Driver Code Ends