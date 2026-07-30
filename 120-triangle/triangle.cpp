class Solution {
public:
    int f(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return triangle[0][0];

        if (j < 0 || j > i)
            return 1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = triangle[i][j] + f(i - 1, j, triangle, dp);
        int diag = triangle[i][j] + f(i - 1, j - 1, triangle, dp);

        return dp[i][j] = min(up, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m);
        for (int i = 0; i < m; i++)
            dp[i] = vector<int>(triangle[i].size(), -1);

        int ans = 1e9;

        for (int j = 0; j < triangle[m - 1].size(); j++)
            ans = min(ans, f(m - 1, j, triangle, dp));

        return ans;
    }
};