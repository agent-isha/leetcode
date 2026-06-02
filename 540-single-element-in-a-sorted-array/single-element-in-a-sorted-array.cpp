class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo=0;
        int high=nums.size()-1;
        int n=nums.size()-1;
        int ans=-1;

        if(nums.size()==1){
            return nums[0];
        }

        while(lo<=high){
            int mid=lo+(high-lo)/2;

            if((mid==0 || nums[mid]!=nums[mid-1]) &&
               (mid==n || nums[mid]!=nums[mid+1])){
                ans=nums[mid];
                break;
            }

            if(mid%2==0){
                if(mid!=n && nums[mid]==nums[mid+1]){
                    lo=mid+2;
                }else if(mid==n){
                    ans=nums[mid];
                    break;
                }else{
                    high=mid-1;
                }
            }else{
                if(mid!=0 && nums[mid]==nums[mid-1]){
                    lo=mid+1;
                }else if(mid==0){
                    ans=nums[mid];
                    break;
                }else{
                    high=mid-1;
                }
            }
        }

        return ans;
    }
};