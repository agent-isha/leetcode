class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0;
        int high=nums.size()-1;
        while(lo<high){
            int mid=lo+(high-lo)/2;
            if(mid%2==1){
                mid--;
            }
            if(nums[mid]==nums[mid+1]){
                lo=mid+2;
            }else{
                high=mid;
            }
        }
        return nums[lo];
        
    }
};