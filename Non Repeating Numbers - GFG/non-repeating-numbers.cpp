//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int x=0;
        for(auto it:nums){
            x^=it;
        }
        int mask=1;
        while(1){
            if((mask&x)==0){
                mask=mask<<1;
            }else break;
        }
        int a=0,b=0;
        for(auto it:nums){
            if(it&mask){
                a^=it;
            }else{
                b^=it;
            }
        }
        if(a<b)
        return {a,b};
        return {b,a};
        
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends