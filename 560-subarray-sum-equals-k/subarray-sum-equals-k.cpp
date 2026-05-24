class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int prefixsum=0;
        map<int,int>psum;
        psum[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            int remove=prefixsum-k;
            if(psum.find(remove)!=psum.end()){
                count+=psum[remove];
            }
            
            psum[prefixsum]++;
            
        }
        return count;
        
    }
};