class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string str=countAndSay(n-1);
        string res="";
        for(int i=0;i<str.size();i++){
            int count=1;
            while(str[i]==str[i+1]){
                i++;
                count++;
            }
            res+=to_string(count)+str[i];
        }
        return res;
    }
    
};