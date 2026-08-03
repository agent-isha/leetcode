class Solution {
public:
    int f(int idx, int t, vector<int>& coins, vector<vector<int>>& dp) {

        if(idx == 0){
            if(t % coins[0] == 0)
                return 1;
            return 0;
}

        if(dp[idx][t] != -1)
            return dp[idx][t];

        int notTake = f(idx - 1, t, coins, dp);

        int take = 0;
        if(coins[idx] <= t)
            take = f(idx, t - coins[idx], coins, dp);

        return dp[idx][t] = notTake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        

        return ans;
        
    }
};