//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/
       class Solution{
  public:
  
    void nslnsr(vector<int>&arr , vector<int>&h , int n , string str)
    {
        stack<int>s;
        if(str == "nsl")
        {
            for(int i=0;i<n;i++)
            {
                while(s.size()>0 && h[i] <= h[s.top()])
                {
                    s.pop();
                }
                if(s.size()>0)
                {
                    arr[i] = s.top();
                }
                s.push(i);
            }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                while(s.size()>0 && h[i] <= h[s.top()])
                {
                    s.pop();
                }
                if(!s.empty())
                {
                    arr[i] = s.top();
                }
                s.push(i);
            }
        }
    }
    
    int max_area_of_hist(vector<int>&arr , int size)
    {
        vector<int>left(size,-1);
        vector<int>right(size,size);
        nslnsr(left , arr , size , "nsl");
        nslnsr(right , arr , size , "nsr");
        
        int ans = arr[0];
        for(int i=0;i<size;i++)
        {
            ans = max(ans , (right[i] - left[i] - 1)*arr[i]);
        }
        return ans;
    }
  
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        int maxarea = 0;
        vector<int>v(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j] == 0)
                {
                    v[j] = 0;
                }
                else
                {
                    v[j] += M[i][j];
                }
            }
            maxarea = max(maxarea , max_area_of_hist(v , m));
        }
        return maxarea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends