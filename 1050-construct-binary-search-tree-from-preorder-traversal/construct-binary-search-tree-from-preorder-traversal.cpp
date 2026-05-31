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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();

        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        return bst(preorder, 0, n - 1, inorder, 0, n - 1);
    }

    TreeNode* bst(vector<int>& preorder, int pstart, int pend,
                  vector<int>& inorder, int instart, int inend) {

        if (pstart > pend || instart > inend)
            return NULL;

        TreeNode* root = new TreeNode(preorder[pstart]);

        int idx = instart;
        while (idx <= inend && inorder[idx] != root->val)
            idx++;

        int leftSize = idx - instart;

        root->left = bst(preorder,
                         pstart + 1,
                         pstart + leftSize,
                         inorder,
                         instart,
                         idx - 1);

        root->right = bst(preorder,
                          pstart + leftSize + 1,
                          pend,
                          inorder,
                          idx + 1,
                          inend);

        return root;
    }
};