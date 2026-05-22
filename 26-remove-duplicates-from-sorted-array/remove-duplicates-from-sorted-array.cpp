class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a=nums.size();
        for(int i=0;i<nums.size()-1;){
            if(nums[i+1]==nums[i]){
                nums.erase(nums.begin()+i+1);
            }else{
                i++;
            }
        }
        return nums.size();

        
    }
};