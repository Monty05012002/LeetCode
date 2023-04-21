//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
     long long gcd(long long a,long long b)
     {
         if(b==0)
         {
             return a;
         }
         return gcd(b,a%b);
     }
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        return {(A*B)/gcd(A,B),gcd(A,B)};
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends