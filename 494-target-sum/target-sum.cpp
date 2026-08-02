class Solution {
public:
    int f(int idx, int sum, vector<int>& nums, int target) {

        if(idx == nums.size()) {
            return (sum == target);
        }

        int plus = f(idx + 1, sum + nums[idx], nums, target);

        int minus = f(idx + 1, sum - nums[idx], nums, target);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return f(0, 0, nums, target);
    }
};