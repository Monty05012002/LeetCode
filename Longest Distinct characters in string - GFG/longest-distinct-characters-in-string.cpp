//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int maxi=0;
    int i=0,j=0;
    unordered_set<char>st;
    int n=S.size();
    while(j<n){
        if(st.find(S[j])==st.end()){
            st.insert(S[j]);
            maxi=max(maxi,(int)st.size());
            j++;
        }else{
            st.erase(S[i]);
            i++;
        }
    }
    return maxi;
    
}