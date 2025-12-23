class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target,
               vector<int>& op, vector<vector<int>>& ans) {

        
        if (target == 0) {
            ans.push_back(op);
            return;
        }

        
        if (idx >= candidates.size() || target < 0) {
            return;
        }

       
        op.push_back(candidates[idx]);
        solve(idx, candidates, target - candidates[idx], op, ans);
        op.pop_back();

        
        solve(idx + 1, candidates, target, op, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(0, candidates, target, op, ans);
        return ans;
    }
};
