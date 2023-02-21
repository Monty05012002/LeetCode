//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y){    
        // code here
        vector<vector<int>>t(N+1,vector<int>(M+1,-1));
        queue<pair<int,int>>q;
        t[x][y]=1;
        q.push({x,y});
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int first=q.front().first;
                int second=q.front().second;
                q.pop();
                if(first>1 && t[first-1][second]==-1 ){
                    q.push({first-1,second});
                    t[first-1][second]=1;
                }
                if(first<N && t[first+1][second]==-1 ){
                    q.push({first+1,second});
                    t[first+1][second]=1;
                }
                if(second>1 && t[first][second-1]==-1 ){
                    q.push({first,second-1});
                    t[first][second-1]=1;
                }
                 if(second<M && t[first][second+1]==-1 ){
                    q.push({first,second+1});
                    t[first][second+1]=1;
                }
            }
            if(!q.empty())
                cnt++;
        }
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends