class Solution {
public:
    string removeDuplicates(string s, int k) {
       string ans="";
        stack<pair<char,int>>s1;
        for(auto it:s){
            if(s1.empty()){
                s1.push({it,1});
            }
            else{
            if(s1.top().first==it){
                s1.top().second++;
                }
                else{
                    s1.push({it,1});
                }
            }
            if(!s1.empty() && k==s1.top().second){
                s1.pop();
            }
        }
        while(!s1.empty()){
            ans+=s1.top().first;
             s1.top().second--;
            if(s1.top().second==0)
            s1.pop();
           
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};