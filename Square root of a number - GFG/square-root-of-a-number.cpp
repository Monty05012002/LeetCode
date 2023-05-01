//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here   
        long long int beg=1,end=x,ans=0;
        while(beg<=end){
            long long int mid=beg+(end-beg)/2;
            if(mid*mid==x) return mid;
            else if(mid*mid>x) end=mid-1;
            else {
                ans=mid;
                beg=mid+1;
                
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends