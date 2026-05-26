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
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left){
                m[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                m[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }

    TreeNode* findnode(TreeNode* root,int start){
        if(root==nullptr)return nullptr;
        if(root->val==start)return root;

        TreeNode* left=findnode(root->left,start);
        if(left)return left;

        return findnode(root->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markparents(root,parent);
        TreeNode * target=findnode(root,start);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int t=-1;

        while(!q.empty()){
            int sz=q.size();
            t++;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]]=true;
                    q.push(parent[node]);
                }
            } 
        }
        return t;
    }
};