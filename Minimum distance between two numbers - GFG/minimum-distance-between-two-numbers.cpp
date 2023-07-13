//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
      int j=0;
            int k=0;
            int count=INT_MAX;
            for(int i=0;i<n;i++){
                if(a[i]==x)
                j=i+1;
                if(a[i]==y)
                k=i+1;
                if(j>0 && k>0){
                    int diff=abs(j-k);
                    count=min(diff,count);
                }
            }
            if(count!=INT_MAX)
            return count;
            else
            return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends