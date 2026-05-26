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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        map<int,int>imap;
        for(int i=0;i<n;i++){
            imap[inorder[i]]=i;


        }
        return builttree(inorder,0,n-1,postorder,0,n-1,imap);
    }
    TreeNode*builttree(vector<int>inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,map<int,int>&imap){
        if(poststart>postend||instart>inend){
            return NULL;
        }
        TreeNode*root=new TreeNode(postorder[postend]);
        int inroot=imap[postorder[postend]];
        int numleft=inroot-instart;
        root->left=builttree(inorder,instart,inroot-1,postorder,poststart,poststart+numleft-1,imap);
        root->right=builttree(inorder,inroot+1,inend,postorder,poststart+numleft,postend-1,imap);
        return root;

    
        
    }
};