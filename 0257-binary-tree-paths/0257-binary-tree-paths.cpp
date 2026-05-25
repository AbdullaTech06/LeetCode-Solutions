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
    vector<string> ans;
    void path(TreeNode* node,string s){
        if(node==nullptr)return;
        s+=to_string(node->val);
        if(node->left==nullptr && node->right==nullptr){
            ans.push_back(s);
            return;
        }
        s+="->";
        path(node->left,s);
        path(node->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        path(root,"");
        return ans;
    }
};