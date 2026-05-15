/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<pair<pair<int,int>,int>> v;

    void dfs(TreeNode* root, int row, int col) {

        if(root == NULL) {
            return;
        }

        v.push_back({{col,row}, root->val});

        dfs(root->left, row + 1, col - 1);

        dfs(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        dfs(root, 0, 0);

        sort(v.begin(), v.end());

        vector<vector<int>> ans;

        int prevCol = v[0].first.first;

        vector<int> temp;

        for(int i = 0; i < v.size(); i++) {

            int col = v[i].first.first;

            int val = v[i].second;

            if(col != prevCol) {

                ans.push_back(temp);

                temp.clear();

                prevCol = col;
            }

            temp.push_back(val);
        }

        ans.push_back(temp);

        return ans;
    }
};