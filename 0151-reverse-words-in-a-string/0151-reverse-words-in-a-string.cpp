class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++){
            string str;
            if(s[i]==' ')
                continue;
            while(s[i]!=' ' && i<s.size()){
                str+=s[i];
                i++;
            }
            st.push(str);
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
            if(!st.empty())
                res+=" ";
        }
        return res;
    }
};