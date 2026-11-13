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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        unsigned long long  ans=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            unsigned long long first=q.front().second;
            unsigned long long  last=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                unsigned long long cur=q.front().second-first;
                q.pop();
                if(i==size-1)last=cur;
                if(node->left) q.push({node->left,cur*2+1});
                if(node->right)q.push({node->right,cur*2+2});
            }
            ans=max(ans,last+1);
        }
        return (int)ans;
    }
};