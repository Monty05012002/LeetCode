//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minTime(int S1, int S2, int N){
        // code here
        int minTime,maxTime;
        if(S1<=S2){
            minTime=S1;
            maxTime=S2;
        }
        else{
            minTime=S2;
            maxTime=S1;
        }
        if(N*minTime<=maxTime)
        return N*minTime;
        int x=N*maxTime/(S1+S2);
        int a=N-x;
        int b=x+1;
        int c=N-b;
        int temp1=max(x*minTime,a*maxTime);
        int temp2=max(b*minTime,c*maxTime);
        return min(temp1,temp2);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S1, S2, N;
        cin>>S1>>S2>>N;
        
        Solution ob;
        cout<<ob.minTime(S1, S2, N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends