//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    int  minSum(int arr[], int sum,int n){
        bool t[n+1][sum+1];
        for(int i=0;i<n+1;i++){
          for(int j=0;j<sum+1;j++){
              if(i==0)
              t[i][j]=false;
              if(j==0)
              t[i][j]=true;
          }  
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
         vector<int>v;
         for(int i=0;i<=sum/2;i++){
             if(t[n][i]==true)
                 v.push_back(i);
         }
         int ans=INT_MAX;
         for(int i=0;i<v.size();i++){
             ans=min(ans,sum-2*v[i]);
         }
         return ans;
         
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
          return  minSum(arr,sum,n);
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends