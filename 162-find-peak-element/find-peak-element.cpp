class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size()-1;
        int lo=0;
        int high=nums.size()-1;
        if(nums.size()==1){
            return 0;
        }
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[n]>nums[n-1]){
            return n;
        }
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            
            if(mid!=n && nums[mid]<nums[mid+1]){
                lo=mid+1;
            }else{
                if(mid!=0 && nums[mid-1]>nums[mid]){
                    high=mid-1;
                }
                else{
                    return mid;
                }
            }
        }
        return -1;

        
    }
};