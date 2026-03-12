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
    int val=0;
    void isha(TreeNode*root,int&val){
        if(root==NULL){
            return ;
        }
        if(root!=NULL){
            val+=1;
        }
        isha(root->left,val);
        isha(root->right,val);

    }
    int countNodes(TreeNode* root) {
        isha(root,val);
        return val;

        
        
    }
};