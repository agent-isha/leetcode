class Solution {
public:
    vector<int> f(int idx, int prev, vector<int>& nums,
                  vector<vector<vector<int>>>& dp) {

        if (idx == nums.size())
            return {};

        
        if (!dp[idx][prev + 1].empty())
            return dp[idx][prev + 1];

        vector<int> not_take = f(idx + 1, prev, nums, dp);

        vector<int> take;

        if (prev == -1 || nums[idx] % nums[prev] == 0) {
            take = f(idx + 1, idx, nums, dp);
            take.push_back(nums[idx]);
        }

        if (take.size() > not_take.size())
            return dp[idx][prev + 1] = take;

        return dp[idx][prev + 1] = not_take;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n + 1)
        );

        return f(0, -1, nums, dp);
    }
};