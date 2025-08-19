class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        long long ct=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ct++;
            }else{
                sum+=ct*(ct+1)/2;
                ct=0;
            }
        }

        sum+=ct*(ct+1)/2;
        return sum;
        


        
    }
};