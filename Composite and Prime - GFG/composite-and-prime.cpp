//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int Count(int L, int R){
		    // Code here
		    vector<int>t(R+1,true);
		    t[0]=false;
		    t[1]=false;
		    for(int i=2;i<=R;i++){
		        if(t[i]==true){
		            for(int j=2*i;j<=R;j+=i){
		                t[j]=false;
		            }
		        }
		    }
		    int comp=0,pri=0;
		    for(int i=L;i<=R;i++){
		        if(i==1) continue;
		        if(t[i]==true) pri++;
		        else comp++;
		    }
		    return comp-pri;
		    
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int L, R;
		cin >> L >> R;
		Solution obj;
		int ans = obj.Count(L, R);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends