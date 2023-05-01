//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool solve(vector<int>& sweetness,int val,int k){
        int sum=0,c=0;
        for(auto it:sweetness){
            sum+=it;
            if(sum>=val){
                c++;
                sum=0;
            }
        }
        return c>=k+1;
    }
    int maxSweetness(vector<int>& sweetness, int N, int K) {
    // Write your code here.
       int end=0,beg=0;
       for(auto it:sweetness) end+=it;
       int ans=0;
       while(beg<=end){
           int mid=beg+(end-beg)/2;
           if(solve(sweetness,mid,K)){
               ans=mid;
               beg=mid+1;
           }
           else{
               end=mid-1;
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends