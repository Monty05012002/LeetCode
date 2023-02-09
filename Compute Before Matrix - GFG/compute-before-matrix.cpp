//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        // Code here
        vector<vector<int>>before(N,vector<int>(M,0));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i==0 && j==0)
                before[i][j]=after[i][j];
                else if(i!=0 && j==0){
                    before[i][j]=after[i][j]-after[i-1][j];
                }
                else if(i==0 && j!=0){
                    before[i][j]=after[i][j]-after[i][j-1];
                }
                else{
                    before[i][j]=after[i][j]+after[i-1][j-1]-after[i][j-1]-after[i-1][j];
                }
            }
        }
        return before;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}
// } Driver Code Ends