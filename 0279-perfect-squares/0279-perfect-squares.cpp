class Solution {
public:
    int numSquares(int n) {
         vector<int> ans(n+1,INT_MAX);
        ans[0] =0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                    ans[i] = min(ans[i],1+(ans[i-(j*j)]));
            }
        }
        return ans[n]; 
    }
};