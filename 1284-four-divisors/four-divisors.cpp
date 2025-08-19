class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int sum1=0;
        for(int i=0;i<nums.size();i++){
            int ct=0;
            int sum=0;
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0 && j*j<nums[i]){
                    ct+=2;
                    sum+=j;
                    sum+=nums[i]/j;
                    if(ct>4){
                        break;
                    }
                    
                }
                if(j*j==nums[i]){
                    ct+=1;
                    sum+=j;
                }
            }
            if(ct==4){
                sum1+=sum;
                

            }
        }
        
        return sum1;
    }
};