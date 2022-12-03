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
             return mid;
            else if(nums[end]>=nums[mid]) end=mid-1;
            else if(nums[start]<=nums[mid]) start=mid+1;
        }
        return 0;
    }
    int binarySearch(vector<int>& nums,int target,int start,int end){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                end=mid-1;
            else
                start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int index=findMin(nums);
      
        int start=0,end=nums.size()-1;
        int a=binarySearch(nums,target,start,index-1);
        int b=binarySearch(nums,target,index,end);
        if(a==-1 && b==-1)
            return -1;
        else if(a==-1)
            return b;
        else
            return a;
    }
};