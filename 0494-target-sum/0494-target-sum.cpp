class Solution {
public:
    int subset(vector<int>&arr,int sum){
        int n=arr.size();
    int t[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                t[i][j]=0;
            if(j==0)
                t[i][j]=1;
        }
    }
    int mod=1e9+7;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(arr[i-1]<=j){
                t[i][j]=(t[i-1][j-arr[i-1]]+t[i-1][j])%mod;
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
    int findTargetSumWays(vector<int>& arr, int d) {
        int n=arr.size();
        d=abs(d);
         int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
   if(d>sum||(sum+d)%2==1) return 0;
    int s1=(d+sum)/2;
    return subset(arr,s1);
    }
};