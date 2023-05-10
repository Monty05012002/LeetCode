//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve(string temp,int num,int ind){
        if(ind==num){
            cout<<temp<<" ";
            return;
        }
        solve(temp+'0',num,ind+1);
        if(temp[ind-1]!='1')
        solve(temp+'1',num,ind+1);
    }
    void generateBinaryStrings(int num){
        //Write your code
        string temp="";
        return solve(temp,num,0);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        obj.generateBinaryStrings(n);
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends