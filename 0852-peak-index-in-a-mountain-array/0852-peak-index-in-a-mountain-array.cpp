class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int beg=1;
        int end=n-2;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                 return mid;
           else if(arr[mid-1]>arr[mid])
                    end=mid-1;
           else
                    beg=mid+1;
        }
        return 1;
    }
};