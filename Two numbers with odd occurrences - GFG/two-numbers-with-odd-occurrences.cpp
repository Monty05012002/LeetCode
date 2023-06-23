//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int val=0;
        for(int i=0;i<N;i++){
            val^=Arr[i];
        }
        long long int count=0;
        while(val){
            if(val&1)
            break;
            count++;
            val=val>>1;
        }
        long long int a=0,b=0;
        for(int i=0;i<N;i++){
            if((Arr[i]&(1<<count)))
            a^=Arr[i];
            else{
               b= b^Arr[i];
            }
        }
        if(a>b)
        return {a,b};
        return {b,a};
        
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
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends