class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    int solve(int i, string &s, vector<int> &dp) {
        if (i == s.size())
            return -1;  // no cut needed after last partition

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for (int j = i; j < s.size(); j++) {

            if (isPalindrome(s, i, j)) {

                int cuts = 1 + solve(j + 1, s, dp);

                ans = min(ans, cuts);
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, dp);
    }
};