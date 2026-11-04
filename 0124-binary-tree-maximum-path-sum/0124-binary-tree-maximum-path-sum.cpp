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
    int maxval=INT_MIN;
    int maxpath(TreeNode* root){
        if(root==nullptr)return 0;
        int leftval=max(0,maxpath(root->left));
        int rightval=max(0,maxpath(root->right));
        maxval=max(maxval,root->val+leftval+rightval);
        return root->val+max(leftval,rightval);
    }
    int maxPathSum(TreeNode* root) {
        maxpath(root);
        return maxval;
    }
};