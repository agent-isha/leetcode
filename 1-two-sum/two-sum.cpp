class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> temp = nums;

        map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        sort(temp.begin(), temp.end());

        int start = 0;
        int end = temp.size() - 1;

        while(start < end) {

            int sum = temp[start] + temp[end];

            if(sum == target) {

                if(temp[start] == temp[end]) {

                    return {mp[temp[start]][0],
                            mp[temp[start]][1]};
                }

                return {mp[temp[start]][0],
                        mp[temp[end]][0]};
            }

            else if(sum < target) {
                start++;
            }

            else {
                end--;
            }
        }

        return {};
    }
};