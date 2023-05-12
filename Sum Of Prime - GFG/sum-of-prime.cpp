//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> getPrimes(int N) {
        // code here
        vector<bool>t(N+1,true);
        t[0]=false;
        t[1]=false;
        for(int i=2;i<=N;i++){
            if(t[i]){
                for(int j=2*i;j<=N;j+=i){
                    t[j]=false;
                }
            }
        }
        for(int i=2;i<=N/2;i++){
            if(t[i]==true && t[N-i]==true){
                return {i,N-i};
            }
        }
        return {-1,-1};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        vector<int> ptr = ob.getPrimes(N);
        cout << ptr[0]<<" "<<ptr[1] << endl;
    }
    return 0;
}
// } Driver Code Ends