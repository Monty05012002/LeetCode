class Solution {
public:
    void solve(int index,vector<int>vis,vector<string>&arr,int curr,int &maximum){
        if(index<0){
            maximum=max(maximum,curr);
            return;
        }
        int n=arr[index].size();
        int f=0;
        vector<int>temp=vis;
        for(int i=0;i<n;i++){
            char ch=arr[index][i];
            if(temp[ch-'a']==1){
                f=1;
                break;
            }
            temp[ch-'a']=1;
        }
        if(f==0){
            solve(index-1,temp,arr,curr+arr[index].size(),maximum);
        }
        solve(index-1,vis,arr,curr,maximum);
    }
    int maxLength(vector<string>& arr) {
       int start=0;
        int size=arr.size();
        vector<int>vis(26,0);
        int maximum=0;
        solve(size-1,vis,arr,start,maximum);
        return maximum;
    }
};