//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    bool check(long long n){
        if(n==1 ) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)
            return 0;
        }
        return 1;
    }
    long long int largestPrimeFactor(int N){
        // code here
        vector<int>ans;
        for(int i=2;i<=N;i++){
            if(check(i)){
                if(N%i==0){
                    ans.push_back(i);
                }
            }
        }
        return ans[ans.size()-1];
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
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends