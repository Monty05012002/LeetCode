//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort (intervals.begin(), intervals.end());

        for (int i=0; i<n; i++)
        {
            auto curr = intervals[i];

            int j=i+1, start = intervals[i][0], end = intervals[i][1];
            while(j<n && intervals[j][0]<=end)
            {
                end = max(end,intervals[j][1]);
                j++;
            }
            i=j-1;
            ans.push_back({start,end});
        }
        return ans;   
    }
    vector<int>kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
       vector<int>res;
        vector<vector<int>> ans;
        ans = merge(range);
        
        for (int i=0; i<q; i++)
        {
            int j, curr=0, k=queries[i];
            
            for (j=0; j<ans.size(); j++)
            {
                curr += ans[j][1]-ans[j][0]+1;
                if (curr >= k)
                {
                    break;
                }
            }
            
            if (curr>=k)
            {
                res.push_back(ans[j][1]-(curr-k));
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
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
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends