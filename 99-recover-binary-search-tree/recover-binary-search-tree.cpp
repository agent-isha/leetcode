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
    vector<int> inorder1;
    vector<int> inorder2;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        inorder1.push_back(root->val);
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        inorder2 = inorder1;
        sort(inorder2.begin(), inorder2.end());

        int x, y;
        for (int i = 0; i < inorder1.size(); i++) {
            if (inorder1[i] != inorder2[i]) {
                x = inorder1[i];
                y = inorder2[i];
            }
        }

        solve(root, x, y);
    }

    void solve(TreeNode* root, int x, int y) {
        if (!root) return;

        if (root->val == x)
            root->val = y;
        else if (root->val == y)
            root->val = x;

        solve(root->left, x, y);
        solve(root->right, x, y);
    }
};