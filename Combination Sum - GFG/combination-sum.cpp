//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int i,vector<int>&A,int target,vector<int>&temp,vector<vector<int>>&ans){
        if(target==0){
           ans.push_back(temp);
           return;
        }
        for(int ind=i;ind<A.size();ind++){
            if(A[ind-1]!=A[ind] && A[ind]<=target){
            temp.push_back(A[ind]);
            solve(ind,A,target-A[ind],temp,ans);
            temp.pop_back();
           }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        vector<int>temp;
        vector<vector<int>>ans;
        sort(A.begin(),A.end());
        solve(0,A,B,temp,ans);
        return ans;
    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends