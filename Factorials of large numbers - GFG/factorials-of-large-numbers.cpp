//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        // code here
       vector<int>ans;
       int val=0,car=0;
       ans.push_back(1);
       for(int i=2;i<=N;i++){
           for(int j=0;j<ans.size();j++){
               val=ans[j]*i+car;
               ans[j]=val%10;
               car=val/10;
           }
           while(car>0){
               ans.push_back(car%10);
               car/=10;
           }
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
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends