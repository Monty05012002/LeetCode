class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       string s1="",str="";
        for(auto it:word1){
           s1+=it;
        }
        for(auto it:word2){
            str+=it;
        }
        if(s1==str)
            return true;
        return false;
    }
};