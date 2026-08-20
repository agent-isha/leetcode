class Solution {
public:
    int f(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int maxi = 0;

        for (int i = l; i <= r; i++) {

            int coins = nums[l - 1] * nums[i] * nums[r + 1];

            coins += f(l, i - 1, nums, dp);
            coins += f(i + 1, r, nums, dp);

            maxi = max(maxi, coins);
        }

        return dp[l][r] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        return f(1, n, nums, dp);
    }
};