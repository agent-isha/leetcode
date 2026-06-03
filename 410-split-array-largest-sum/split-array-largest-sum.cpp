class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lo=*max_element(nums.begin(),nums.end());
        int sum=0;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int high=sum;
        while(lo<=high){
            int k1=1;
            int numsum=0;
            int mid=lo+(high-lo)/2;
            for(int i=0;i<nums.size();i++){
                if(numsum+nums[i]<=mid){
                    numsum+=nums[i];
                }else{
                    k1++;
                    numsum=nums[i];
                }
            }
            if(k1<=k){
                ans=mid;
                high=mid-1;

            }else{
                lo=mid+1;
            }
        }
        return ans;
        
    }
};