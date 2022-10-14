//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int,int>>s;
       vector<int>v;
       for(int i=0;i<n;i++){
           if(s.size()==0){
               v.push_back(-1);
           }
           else if(s.size()>0 && s.top().first>price[i]){
               v.push_back(s.top().second);
           }
           else if(s.size()>0 && s.top().first<=price[i]){
               while(s.size()>0 && s.top().first<=price[i])
               s.pop();
               if(s.size()==0)
               v.push_back(-1);
               else
               v.push_back(s.top().second);
           }
           s.push({price[i],i});
       }
       vector<int>ans;
       for(int i=0;i<n;i++){
           ans.push_back(i-v[i]);
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
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends