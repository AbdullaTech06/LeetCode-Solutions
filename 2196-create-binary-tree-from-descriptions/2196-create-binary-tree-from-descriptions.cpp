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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> m;
        unordered_set<int> childnode;
        for(auto it:descriptions){
            int parent=it[0];
            int child=it[1];
            int isleft=it[2];
            if(!m.count(parent)){
                m[parent]=new TreeNode(parent);
            }
            if(!m.count(child)){
                m[child]=new TreeNode(child);
            }
            if(isleft){
                m[parent]->left=m[child];
            }else{
                m[parent]->right=m[child];
            }
            childnode.insert(child);
        }
        for(auto it:descriptions){
            int parent=it[0];
            if(!childnode.count(parent))return m[parent];
        }
        return nullptr;
    }
};