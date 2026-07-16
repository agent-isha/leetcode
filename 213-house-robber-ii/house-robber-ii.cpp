class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& dp, int start) {
        if (idx < start)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int pick = nums[idx] + f(idx - 2, nums, dp, start);
        int notPick = f(idx - 1, nums, dp, start);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Rob from house 0 to n-2
        vector<int> dp1(n, -1);
        int ans1 = f(n - 2, nums, dp1, 0);

        // Rob from house 1 to n-1
        vector<int> dp2(n, -1);
        int ans2 = f(n - 1, nums, dp2, 1);

        return max(ans1, ans2);
    }
};