class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(char it:s){
            if(!st.empty()&&(it+32==st.top()||it-32==st.top())){
                st.pop();
            }
            else{
            st.push(it);}
        }
        string ans;
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};