class Solution {
public:
    void solve(vector<int> op, vector<int> ip, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            ans.push_back(op);
            return;
        }
        if (target < 0 || ip.empty()) {
            return;
        }

        vector<int> op1 = op;
        vector<int> op2 = op;

        int picked = ip[0];

        
        op1.push_back(picked);
        vector<int> ip1 = ip;
        ip1.erase(ip1.begin());
        solve(op1, ip1, ans, target - picked);

        
        vector<int> ip2 = ip;
        while (!ip2.empty() && ip2[0] == picked) {
            ip2.erase(ip2.begin());
        }
        solve(op2, ip2, ans, target);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>> ans;
        vector<int> op;
        solve(op, candidates, ans, target);
        return ans;
    }
};
