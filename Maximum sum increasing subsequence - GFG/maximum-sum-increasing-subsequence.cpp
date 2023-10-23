//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int t[n];
	    for(int i=0;i<n;i++){
	        t[i]=arr[i];
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                t[i]=max(t[j]+arr[i],t[i]);
	            }
	        }
	    }
	    return *max_element(t,t+n);
	    
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
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends