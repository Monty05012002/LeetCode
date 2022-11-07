class Solution {
public:
    int maximum69Number (int num) {
      int temp=num;
      int countdigit=-1;
      int present=-2;
        while(temp!=0){
            int rem=temp%10;
            countdigit++;
            if(rem==6) present=countdigit;
            temp=temp/10;
        }
        if(present==-2)
            return num;
        return num+(3 * pow(10, present));
    }
};