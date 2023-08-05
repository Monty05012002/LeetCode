//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
 
    bool solve(int ind,string &A,unordered_map<string,int>&mp){
        if(ind==A.size()) return true;
        bool flag=false;
        string temp="";
        for(int i=ind;i<A.size();i++){
            temp+=A[i];
            if(mp[temp]){
                flag|=solve(i+1,A,mp);
            }
        }
        return flag;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string,int>mp;
        for(auto it:B) mp[it]++;
        return solve(0,A,mp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends