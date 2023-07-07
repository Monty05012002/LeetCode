//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int solve(int ind,vector<int>&arr,vector<int>&t,int n){
        if(ind>=n || ind<0)
        return 1;
        if(t[ind]!=-1) return t[ind];
        t[ind]=0;
        t[ind]=solve(ind+arr[ind],arr,t,n);
    }
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<int>t(n,-1);
        for(int i=0;i<n;i++){
            if(t[i]==-1)
            solve(i,arr,t,n);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(t[i]==1)
            count++;
        }
        return count;
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends