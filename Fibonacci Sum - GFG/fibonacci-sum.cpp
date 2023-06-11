//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int N){
        //code here
         if(N<=1) return N;         
        long long int mod=1e9+7;
        long long int ans=0;
        long long int a=1,b=1,c;
        ans+=a+b;
        
        for(int i=3;i<=N;i++){
            c=(a+b)%mod;
            ans=(ans+c)%mod;
            a=b;
            b=c;
        }
        return ans%mod;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends