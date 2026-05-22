class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int>v;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1 && i!=nums.size()-1){
                count++;
            }else if(i==nums.size()-1 && nums[i]==1){
                v.push_back(count+1);
                
            }else{
                v.push_back(count);
                count=0;
            }
        }
        
        int a=*max_element(v.begin(),v.end());
        return a;


        
    }
};