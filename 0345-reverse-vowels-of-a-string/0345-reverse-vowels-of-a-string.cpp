class Solution {
public:
    string reverseVowels(string s) {
         int i=0,j=s.length()-1;
        set<char>ch;
        ch.insert('a');
        ch.insert('e');
        ch.insert('i');
        ch.insert('o');
        ch.insert('u');
         ch.insert('A');
        ch.insert('E');
        ch.insert('I');
        ch.insert('O');
        ch.insert('U');
        
        
        while(i<j){
            if(ch.find(s[i])!=ch.end() && ch.find(s[j])!=ch.end()){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(ch.find(s[i])!=ch.end() && ch.find(s[j])==ch.end())
                j--;
            else if(ch.find(s[i])==ch.end() && ch.find(s[j])!=ch.end())
                i++;
            else{
                j--;
                i++;
            }
        }
        return s;
    }
};