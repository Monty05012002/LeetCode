//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A){
        // Code here
        vector<int>left(N),right(N);
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<N;i++){
            maxi=max(A[i],maxi);
            left[i]=maxi;
        }
        for(int i=N-1;i>=0;i--){
            mini=min(A[i],mini);
            right[i]=mini;
        }
        int count=0;
        for(int i=1;i<N;i++){
            if(left[i-1]+right[i]>=K) count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends