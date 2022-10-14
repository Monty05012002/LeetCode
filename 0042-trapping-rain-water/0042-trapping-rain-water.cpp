class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>maxr(n,0),maxl(n,0),water(n);
        maxl[0]=height[0];
        for(int i=1;i<n;i++){
            maxl[i]=max(maxl[i-1],height[i]);
        }
        maxr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxr[i]=max(maxr[i+1],height[i]);
        }
        for(int i=0;i<n;i++){
            water[i]=min(maxr[i],maxl[i])-height[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=water[i];
        }
        return sum;
        
    }
};