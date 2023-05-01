//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     long long solve(vector<int>&piles,int mid){
        long long total=0;
        for(auto it:piles){
            int temp=ceil(it/(double)mid);
           total+=temp;
        }
        return total;
    }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int end=*max_element(piles.begin(),piles.end());
        int beg=1;
        int ans=0;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(solve(piles,mid)<=H){
                ans=mid;
                end=mid-1;
            }else{
                beg=mid+1;
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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends