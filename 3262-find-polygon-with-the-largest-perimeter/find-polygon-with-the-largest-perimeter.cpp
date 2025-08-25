class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        int a;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        for(int i=nums.size()-1;i>0;i--){
            if(sum-nums[i]<=nums[i]){
                sum-=nums[i];
            }else{
                a=i;
                break;
                
            }
        }
        if(a>=2){
            return sum;
        }else{
            return -1;
        }
        
        

        
    }
};