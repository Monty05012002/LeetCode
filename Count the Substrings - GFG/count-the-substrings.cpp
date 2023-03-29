//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string S)
    {
        // code here
        int count=0;
        for(int i=0;i<S.size();i++){
            int upper=0,lower=0;
            for(int j=i;j<S.size();j++){
                if(isupper(S[j])) upper++;
                else lower++;
                 if(lower==upper) count++;
            }
           
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends