class Solution {
public:
    bool closeStrings(string word1, string word2) {
         if(word1.size()!=word2.size())
            return false;
        vector<int>first(26,0),second(26,0);
        set<char>s1,s2;
        for(auto it:word1){
            first[it-'a']++;
            s1.insert(it);
        }
         for(auto it:word2){
            second[it-'a']++;
            s2.insert(it);
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        return second==first&&s1==s2;
    }
};