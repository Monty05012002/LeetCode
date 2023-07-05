//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
              vector<vector<long long>>t(n+1,vector<long long>(2,0));
        t[n][0]=t[n][1]=0;
        for(int ind=n-1;ind>=0;ind--){
            int profit=0;
            for(int buy=0;buy<2;buy++){
                if(buy){
                    profit=max(-prices[ind]+t[ind+1][0],t[ind+1][1]);
                }
                else{
                    profit=max(prices[ind]+t[ind+1][1],t[ind+1][0]);
                }
                 t[ind][buy]=profit;
            }
           
        }
        return t[0][1];

    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends