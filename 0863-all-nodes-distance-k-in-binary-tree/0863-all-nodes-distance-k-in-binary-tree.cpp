/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &m,TreeNode* target){
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>m;
        markparents(root,m,target);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=true;
        int currlvl=0;

        while(!q.empty()){
            int sz=q.size();
            if(currlvl==k)break;
            currlvl++;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=true;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=true;
                }
                if(m[node] && !vis[m[node]]){
                    q.push(m[node]);
                    vis[m[node]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};