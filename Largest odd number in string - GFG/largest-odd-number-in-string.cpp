//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string num) {
        // your code here
         for(int i=num.size()-1;i>=0;i--){
            int a=num[i]-'0';
            if(a%2==0) num.pop_back();
            else break;
        }
        return num;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends