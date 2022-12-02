class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int N=nums.size();
        while(start<=end){
            int mid=start+(end-start)/2;
            int prev=(mid+N-1)%N;
            int next=(mid+1)%N;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next])
             return nums[mid];
            else if(nums[end]>=nums[mid]) end=mid-1;
            else if(nums[start]<=nums[mid]) start=mid+1;
        }
        return 0;
    }
};