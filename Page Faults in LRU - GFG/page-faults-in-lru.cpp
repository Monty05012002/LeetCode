//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        vector<int>s;
        int count=0;
          for(int i=0;i<N;i++){
              auto it=find(s.begin(),s.end(),pages[i]);
              if(it==s.end()){
                  count++;
                  if(s.size()==C) s.erase(s.begin());
                  s.push_back(pages[i]);
              }
              else{
                  s.erase(it);
                  s.push_back(pages[i]);
              }
          }
          return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends