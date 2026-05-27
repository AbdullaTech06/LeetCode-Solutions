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
    unordered_map<int,int> m;
    int idx;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int left,int right){
        if(left>right)return nullptr;
        int rootval=postorder[idx];
        idx--;
        TreeNode* root=new TreeNode(rootval);
        int pos=m[rootval];
        root->right=solve(inorder,postorder,pos+1,right);
        root->left=solve(inorder,postorder,left,pos-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        idx=n-1;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return solve(inorder,postorder,0,inorder.size()-1);
    }
};