//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool solve(int n,int k,int target,vector<int>& coins, vector<vector<vector<int>>>&t){
        if(target==0){
            if(k==0)return true;
            else return false;
        }
        if(n<=0 || k==0) return false;
        if(t[n][k][target]!=-1) return t[n][k][target];
        else{
        if(coins[n-1]<=target){
            bool take=solve(n,k-1,target-coins[n-1],coins,t);
            bool ntake=solve(n-1,k,target,coins,t);
            return t[n][k][target]=take||ntake;
        }else{
            return t[n][k][target]=solve(n-1,k,target,coins,t);
        }
            
        }
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        // code here
        vector<vector<vector<int>>>t(N+1,vector<vector<int>>(K+1,vector<int>(target+1,-1)));
        return solve(N,K,target,coins,t);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends