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
    int maxpathdown(TreeNode* node,int &mx){
        if(node==nullptr)return 0;
        int l=max(0,maxpathdown(node->left,mx));
        int r=max(0,maxpathdown(node->right,mx));
        mx=max(mx,l+r+node->val);

        return max(l,r)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        maxpathdown(root,mx);
        return mx;
    }
};