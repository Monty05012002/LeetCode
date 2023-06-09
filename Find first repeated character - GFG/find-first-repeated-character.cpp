//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    vector<int>mp(26,0);
    for(auto it:s){
        if(mp[it-'a']>0)
         {
             string a="";
            a+=it;
            return a;
        }
        mp[it-'a']++;
    }
    return "-1";
}