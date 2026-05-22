class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;

        }
        int b=nums.size();
        int a=freq.size();
        for (int i=freq.size();i<b;i++){
            nums.erase(nums.begin()+i);

        }
        int i=0;
        for(auto a:freq){
            nums[i]=a.first;
            
            i++;
        }
        sort(nums.begin(),nums.end());
        return a;


        
    }
};