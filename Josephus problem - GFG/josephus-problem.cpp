//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method */

class Solution
{
    public:
     void solve(vector<int>&v,int k,int &ans,int ind){
       if(v.size()==1){
           ans=v[0];
           return;
       }
     
       ind=(ind+k)%v.size();
       v.erase(v.begin()+ind);
       solve(v,k,ans,ind);
   }
    int josephus(int n, int k)
    {
       //Your code here
       vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
       k--;
        int ans=-1;
        solve(v,k,ans,0);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;//testcases
	while(t--)
	{
		int n,k;
		cin>>n>>k;//taking input n and k
		
		//calling josephus() function
		Solution ob;
		cout<<ob.josephus(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends