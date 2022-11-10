class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n=coins.size();
        int t[n+1][sum+1];
        for(int j=0;j<=sum;j++)
            t[0][j]=INT_MAX-1;
        for(int i=1;i<=n;i++)
            t[i][0]=0;
        for(int j=1;j<=sum;j++){
            if(j%coins[0]==0){
                t[1][j]=j/coins[0];
            }
            else{
                t[1][j]=INT_MAX-1;
            }
        }
        for(int i=2;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(coins[i-1]<=j){
                    t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        if(t[n][sum]>sum) return -1;
        return t[n][sum];
    }
};