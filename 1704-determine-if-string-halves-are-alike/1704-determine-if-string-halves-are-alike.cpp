class Solution {
public:
    bool halvesAreAlike(string s) {
        int size=s.size()-1;
        int mid=(0+size)/2;
        string a=s.substr(0,mid+1);
        string b=s.substr(mid+1,size+1);
        int count1=0,count2=0;
        for(int i=0;i<a.size();i++){
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u'||a[i]=='A'||a[i]=='E'||a[i]=='I'||a[i]=='O'||a[i]=='U'){
                count1++;
            }
        }
          for(int i=0;i<b.size();i++){
            if(b[i]=='a'||b[i]=='e'||b[i]=='i'||b[i]=='o'||b[i]=='u'||b[i]=='A'||b[i]=='E'||b[i]=='I'||b[i]=='O'||b[i]=='U'){
                count2++;
            }
        }
        return count1==count2;
    }
};