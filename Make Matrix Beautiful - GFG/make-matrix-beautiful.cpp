//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        vector<int>row;
        vector<int>col;
        int maxSumi=INT_MIN,maxSumj=INT_MIN;
        for(int i=0;i<n;i++){
            int sum1=0,sum2=0;
            for(int j=0;j<n;j++){
                sum1+=matrix[i][j];
                sum2+=matrix[j][i];
            }
            maxSumi=max(sum1,maxSumi);
            row.push_back(sum1);
            maxSumj=max(sum2,maxSumj);
            col.push_back(sum2);
        }
        int count1=0,count2=0;
        for(int i=0;i<n;i++){
            count1+=(maxSumi-row[i]);
            count2+=(maxSumj-col[i]);
        }
        return max(count2,count1);
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends