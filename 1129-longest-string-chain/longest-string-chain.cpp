class Solution {
public:

    int f(int idx, vector<string>& words,
          unordered_map<string, int>& mp,
          vector<int>& dp) {

        if (dp[idx] != -1)
            return dp[idx];

        int ans = 1;

        string curr = words[idx];

    
        for (int i = 0; i < curr.size(); i++) {

            string prev = curr;
            prev.erase(i, 1);

          
            if (mp.count(prev)) {
                int prevIdx = mp[prev];

                ans = max(ans, 1 + f(prevIdx, words, mp, dp));
            }
        }

        return dp[idx] = ans;
    }

    int longestStrChain(vector<string>& words) {

        int n = words.size();

       

       
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            mp[words[i]] = i;
        }

        vector<int> dp(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, f(i, words, mp, dp));
        }

        return ans;
    }
};