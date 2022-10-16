//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        int c[N][N]={0};
        for(int d=1;d<N;d++){
            for(int i=1;i<N-d;i++){
                int j=i+d;
                int mini=INT_MAX;
                for(int k=i;k<j;k++){
                    int q=c[i][k]+c[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    if(q<mini){
                        mini=q;
                    }
                }
                 c[i][j]=mini;
            }
        }
        return c[1][N-1];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends