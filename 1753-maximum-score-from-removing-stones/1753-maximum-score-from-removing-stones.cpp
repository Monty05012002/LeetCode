class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>maxh;
        maxh.push(a);
        maxh.push(b);
        maxh.push(c);
        int count=0;
        while(maxh.size()>=2){
            int first=maxh.top();
            maxh.pop();
            int second=maxh.top();
            maxh.pop();
            if(first>0 && second>0){
                maxh.push(first-1);
                maxh.push(second-1);
                count++;
            }
        }
        return count;
    }
};