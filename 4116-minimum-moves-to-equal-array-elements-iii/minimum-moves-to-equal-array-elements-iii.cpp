class Solution {
public:
    int minMoves(vector<int>& nums) {
        int bigg=*max_element(nums.begin(),nums.end());
        int count=0;
        for(int i=0;i<nums.size();i++){
            count+=bigg-nums[i];

        }
        return count;
        
    }
};