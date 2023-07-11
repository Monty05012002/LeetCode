//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        stack<int>s1;
        int count=0;
        s1.push(-1);
      for(int i=0;i<s.length();i++){
          int top=s1.top();
          if(s1.top()!=-1 && s[top]=='(' && s[i]==')')
          {
              s1.pop();
              count=max(count,i-s1.top());
              
          }
          else{
              s1.push(i);
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
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends