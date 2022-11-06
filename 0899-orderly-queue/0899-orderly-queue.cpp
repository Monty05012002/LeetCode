class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1){
            sort(s.begin(),s.end());
            return s; 
        }
            vector<string>v;
            for(int i=0;i<s.size();i++){
                char ch=s[0];
                s.erase(s.begin());
                s.push_back(ch);
                v.push_back(s);
            }
            sort(v.begin(),v.end());
            return v[0];
        }

};