//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
   void solve(int ind, vector<string> &res, string &op, string &s){
        if(ind == s.size()){
            res.push_back(op);
            return;
        }
        if(ind == 0){
            op.push_back(s[ind]);
            solve(ind+1, res, op, s);
            op.pop_back();
        }
        else{
            string op1 = op;
            op1.push_back(' ');
            op1.push_back(s[ind]);
            solve(ind+1, res, op1, s);
            string op2 = op;
            op2.push_back(s[ind]);
            solve(ind+1, res, op2, s);
        }
    }
    vector<string> permutation(string S){
        // Code Here
         vector<string>res;
        string op = "";
        solve(0, res, op, S);
        return res;
        
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends