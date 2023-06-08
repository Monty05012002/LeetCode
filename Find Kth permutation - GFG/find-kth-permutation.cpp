//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void next_per(vector<int>& a, int n, int k){
        int i,j;
        for(i=n-1;i>=1;i--){
            if(a[i]>a[i-1]){
                break;
            }
        }
        
        j=i-1;
        while(i<n){
            if(a[i]>a[j]){
                i++;
            }else{
                break;
            }
        }
        i--;
        swap(a[i],a[j]);
        
        reverse(a.begin()+j+1,a.end());
    }
    string kthPermutation(int n, int k)
    {
        // code here
       vector<int>a;
        
        for(int i=1;i<=n;i++){
            a.push_back(i);
        }
        
        for(int i=1;i<k;i++){
            next_per(a,n,k);
        }
          string ans;
        for(int i=0;i<a.size();i++){
            ans+= '0'+a[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends