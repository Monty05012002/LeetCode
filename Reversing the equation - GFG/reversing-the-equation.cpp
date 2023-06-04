//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            int n=s.size();
            stack<string>st;
            string str="";
            int i=0;
            while(i<n){
                if(isdigit(s[i])){
                      while(i<n && isdigit(s[i])){
                          str+=s[i];
                          i++;
                      }
                }
                else{
                    st.push(str);
                    string a;
                    a=s[i];
                    st.push(a);
                    str="";
                    i++;
                }
            }
            if(isdigit(s[n-1])){
                st.push(str);
            }
            string ans="";
            while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
            return ans;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends