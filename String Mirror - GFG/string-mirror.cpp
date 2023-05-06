//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string ans="";
        ans+=str[0];
        for(int i=1;i<str.size();i++){
            if(str[i]>str[i-1]) break;
            if(str[i]==str[i-1] && str[i]==str[0]) break;
            ans+=str[i];
        }
        string s=ans;
        reverse(s.begin(),s.end());
        ans+=s;
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends