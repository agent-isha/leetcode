class Solution {
public:
    bool f(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {

        if(target == 0)
            return true;

        if(i == 0)
            return nums[0] == target;

        if(dp[i][target] != -1)
            return dp[i][target];

        bool notTake = f(i-1, target, nums, dp);

        bool take = false;
        if(nums[i] <= target)
            take = f(i-1, target-nums[i], nums, dp);

        return dp[i][target] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {

        int total = 0;
        for(int x : nums)
            total += x;

        if(total % 2)
            return false;

        int target = total / 2;

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n-1, target, nums, dp);
    }
};