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
    bool mirror(TreeNode* LeftNode,TreeNode* RightNode){
        if(LeftNode==nullptr && RightNode==nullptr)return true;
        if(LeftNode==nullptr || RightNode==nullptr)return false;
        if(LeftNode->val!=RightNode->val) return false;
        return mirror(LeftNode->left,RightNode->right) && mirror(RightNode->left,LeftNode->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;
        return mirror(root->left,root->right);        
    }
};