class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end(), greater<int>());

        if(nums == temp) {
            reverse(nums.begin(), nums.end());
            return;
        }

        
        for(int i = n - 2; i >= 0; i--) {

            int mini = INT_MAX;
            int index = -1;

            
            for(int j = i + 1; j < n; j++) {

                if(nums[j] > nums[i]) {

                    if(nums[j] - nums[i] < mini) {
                        mini = nums[j] - nums[i];
                        index = j;
                    }
                }
            }

            
            if(index != -1) {

                swap(nums[i], nums[index]);

                
                sort(nums.begin() + i + 1, nums.end());

                return;
            }
        }
    }
};