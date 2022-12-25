//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int solve(int i,int j,string s,int isTrue,vector<vector<vector<int>>>&t){
        if(i>j) return 0;
        if(i==j){
            if(isTrue)
            return s[i]=='T';
            else
            return s[i]=='F';
        }
        if(t[i][j][isTrue]!=-1) return t[i][j][isTrue];
        int ways=0;
        int mod=1003;
        for(int ind=i+1;ind<j;ind+=2){
            int rT=solve(i,ind-1,s,1,t);
            int rF=solve(i,ind-1,s,0,t);
            int lT=solve(ind+1,j,s,1,t);
            int lF=solve(ind+1,j,s,0,t);
            if(s[ind]=='&'){
                if(isTrue)
                ways=(ways+(rT*lT))%mod;
                else
                ways=(ways+(rT*lF)%mod+(lT*rF)%mod+(rF*lF)%mod)%mod;
            }
            
            else if(s[ind]=='|'){
                if(isTrue){
                    ways=(ways+(rT*lF)%mod+(lT*rF)%mod+(rT*lT)%mod)%mod;
                }
                else
                ways=(ways+(rF*lF)%mod)%mod;
            }
            else{
                if(isTrue)
                 ways=(ways+((rT*lF)%mod)+((lT*rF)%mod))%mod;
                 else
                  ways=(ways+((rF*lF)%mod)+((rT*lT)%mod))%mod;
            }
        }
        return t[i][j][isTrue]=ways;
    }
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>>t(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return solve(0,N-1,S,1,t);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends