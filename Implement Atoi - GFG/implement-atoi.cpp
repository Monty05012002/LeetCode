//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        string s="";
        for(int i=0;i<str.size();i++){
            if(str[i]=='-' && i==0){
                s+=str[i];
            }
            else if(isdigit(str[i])){
                s+=str[i];
            }
            else{
                return -1;
            }
             
            
        }
        return stoi(s);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends