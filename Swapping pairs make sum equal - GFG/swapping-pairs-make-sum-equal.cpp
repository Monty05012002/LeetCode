//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int A[], int n, int B[], int m)
	{
        // Your code goes here
        long long sum1=0;
        long long sum2=0;
        for(int i=0;i<n;i++){
            sum1+=A[i];
        }
        for(int i=0;i<m;i++){
            sum2+=B[i];
        }
        if((sum2+sum1)%2!=0) return -1;
        if(sum1==sum2) return 1;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[A[i]]=1;
        }
        int x=(sum2-sum1)/2;
        for(int i=0;i<m;i++){
            if(mp.find(B[i]-x)!=mp.end())
            return 1;
        }
        return -1;
        
	}
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends