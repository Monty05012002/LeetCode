//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sentencePalindrome(string s) 
	{
	    // code here 
	    string s1="";
	    for(int i=0;i<s.size();i++){
	        if(isalpha(s[i]))
	        s1+=s[i];
	    }
	    int i=0,j=s1.size()-1;
	    while(i<j){
	        if(s1[i++]!=s1[j--])
	        return false;
	    }
	    return true;
	}
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution ob;
        cout<<ob.sentencePalindrome(str)<<endl;
    }
    return 0;
}  


// } Driver Code Ends