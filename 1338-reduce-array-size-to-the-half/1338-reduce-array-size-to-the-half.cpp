class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int k=arr.size();
        unordered_map<int,int>mp;
        priority_queue<int>maxh;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        for(auto it:mp)
            maxh.push(it.second);
        int count=0;
        while(k>arr.size()/2){
            k-=maxh.top();
            count++;
            maxh.pop();
        }
        return count;
    }
};