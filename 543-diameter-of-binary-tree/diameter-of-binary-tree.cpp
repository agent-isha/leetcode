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
    int diam(TreeNode*root,int &ans){
        if(root==nullptr){
            return 0;
        }
        int left=diam(root->left,ans);
        int right=diam(root->right,ans);
        ans=max(left+right,ans);
        return 1+max(left,right);

        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        diam(root,ans);
        return ans;
        
    }
};