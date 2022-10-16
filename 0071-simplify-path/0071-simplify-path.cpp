class Solution {
public:
    string simplifyPath(string path) {
        stack<string>s;
        string ans;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/')
                continue;
            string str;
            while(i<path.size() && path[i]!='/'){
                str+=path[i];
                ++i;
            }
            if(str==".")
                continue;
            else if(str==".."){
                if(!s.empty())
                    s.pop();
            }
            else
                s.push(str);
        }
        if(s.empty())
            return "/";
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        return ans;
        }
};