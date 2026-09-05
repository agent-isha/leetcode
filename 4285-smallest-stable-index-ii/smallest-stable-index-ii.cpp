class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>maxi;
        vector<int>mini;
        int maxii=0;
        for(int i=0;i<nums.size();i++){
            if(maxii<nums[i]){
                maxii=nums[i];

            }
            maxi.push_back(maxii);

        }
        int minii=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            if(minii>nums[i]){
                minii=nums[i];
            }
            mini.push_back(minii);
        }
        reverse(mini.begin(),mini.end());
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if((maxi[i]-mini[i])<=k){
                return i;
            }
            
        }
        return -1;

    }
};