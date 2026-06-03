class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int high=*max_element(nums.begin(),nums.end());
        if(nums.size()>threshold){
            return -1;
        }
        int ans;
        while(lo<=high){
            int divisor=0;
            int mid=lo+(high-lo)/2;
            for(int i=0;i<nums.size();i++){
                divisor+=(nums[i]+mid-1)/mid;
                
            }
            if(divisor<=threshold){
                ans=mid;
                high=mid-1;
            }else{
                lo=mid+1;
            }

        }
        return ans;
        
    }
};