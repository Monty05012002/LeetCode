//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        if(str.size()==0) return "-1";
        unordered_map<char,int>mp;
        priority_queue<pair<int,char>>maxh;
        for(auto it:str) mp[it]++;
        for(auto it:mp) {
            maxh.push({it.second,it.first});
        }
        if(maxh.size()==1) return "-1";
        string ans="";
        while(maxh.size()>1){
            auto top=maxh.top();
            maxh.pop();
            ans+=top.second;
            top.first--;
             auto top1=maxh.top();
            maxh.pop();
            ans+=top1.second;
            top1.first--;
            if(top.first>0) maxh.push({top.first,top.second});
            if(top1.first>0) maxh.push({top1.first,top1.second});
        }
        if(!maxh.empty()){
            if(maxh.top().first>1) return "-1";
            ans+=maxh.top().second;
        }
         return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends