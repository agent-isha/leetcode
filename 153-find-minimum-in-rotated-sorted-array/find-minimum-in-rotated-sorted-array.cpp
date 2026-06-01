class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0;
        int high=nums.size()-1;
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            if(mid>0&&nums[mid-1]>nums[mid]){
                return nums[mid];
            }
            if(nums[lo]<=nums[high]){
                return nums[lo];
            }
            if(nums[lo]<=nums[mid]){
                lo=mid+1;
            }else{
                high=mid-1;
            }
        }
        return -1;
        
    }
};