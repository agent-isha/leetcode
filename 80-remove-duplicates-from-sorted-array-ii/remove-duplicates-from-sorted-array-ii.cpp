class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ct=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                ct++;
                if(ct>2){
                    nums.erase(nums.begin()+i);
                    i--;
                }
            }else{
                ct=1;
            }
            
        }
        return nums.size();

         
        
    }
};