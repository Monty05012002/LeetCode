class Solution {
public:
    string removeDuplicates(string s) {
       stack<char>s1;
           string ans="";
        for(char it:s){
            if(!s1.empty() && s1.top()==it){
                s1.pop();
             ans.pop_back();
            }
            else{
                s1.push(it);
                ans+=it;
            }
        }
        return ans;
    }
};