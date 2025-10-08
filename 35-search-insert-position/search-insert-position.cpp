class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo=0;
        int high=nums.size()-1;
        while(lo<high){
            int mid=lo +(high-lo)/2;

            
            if(nums[mid]<target){
                lo=mid+1;
            }else{
                high=mid;
            }
        }
        if(target>nums[nums.size()-1]){
            return nums.size();
        }else{
            return lo;
        }
        

        
    }
};