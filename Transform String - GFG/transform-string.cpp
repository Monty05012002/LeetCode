//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
       unordered_map<char,int>mp;
        if(A.size()!=B.size())
        return -1;
        for(auto it:A){
            mp[it]++;
        }
        for(auto it:B){
            mp[it]--;
        }
        for(auto it:mp){
            if(it.second)
            return -1;
        }
        int count=0;
        int i=A.size()-1;
        int j=B.size()-1;
        while(i>=0 && j>=0){
            if(A[i]==B[j]){
                i--;
                j--;
            }
            else{
                i--;
                count++;
            }
            
        }
        return count;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends