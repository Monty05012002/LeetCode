//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int solve(int curr,int N,int r[],int g[],int b[],int prev,  vector<vector<long long int>>&t){
        if(curr==N)
        return 0;
        if(t[curr][prev]!=-1)
        return t[curr][prev];
        long long int tr=1e11,tg=1e11,tb=1e11;
        if(prev==0){
            tr=r[curr]+solve(curr+1,N,r,g,b,1,t);
            tg=g[curr]+solve(curr+1,N,r,g,b,2,t);
            tb=b[curr]+solve(curr+1,N,r,g,b,3,t);
        }
        else if(prev==1){
            tg=g[curr]+solve(curr+1,N,r,g,b,2,t);
            tb=b[curr]+solve(curr+1,N,r,g,b,3,t);
        }
        else if(prev==2){
              tr=r[curr]+solve(curr+1,N,r,g,b,1,t);
              tb=b[curr]+solve(curr+1,N,r,g,b,3,t);
        }
        else{
         tr=r[curr]+solve(curr+1,N,r,g,b,1,t);
         tg=g[curr]+solve(curr+1,N,r,g,b,2,t);
        }
        return t[curr][prev]= min(tr,min(tb,tg));
    }
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        // code here 
        vector<vector<long long int>>t(N,vector<long long int>(4,-1));
        return solve(0,N,r,g,b,0,t);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends