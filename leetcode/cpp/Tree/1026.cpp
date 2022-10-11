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
    unordered_map<TreeNode*, pair<int,int>>m;
    void dfs(TreeNode* root){
        if(!root)
            return;
        else if(!root->left && !root->right){
            m[root] = {root->val, root->val};
        }
        else if(root->left && !root->right){
            dfs(root->left);
            m[root] = {min(root->val, m[root->left].first), max(root->val, m[root->left].second)};
        }

        else if(!root->left && root->right){
            dfs(root->right);
            m[root] = {min(root->val, m[root->right].first), max(root->val, m[root->right].second)};
        }

        else{
            dfs(root->left);
            dfs(root->right);
            auto it = m[root->left];
            auto it2 = m[root->right];
            int mi = min(root->val, min(it.first, it2.first));
            int n = max(root->val, max(it.second, it2.second));

            m[root] = {mi,n};
        }

    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);

        int maxi = INT_MIN;

        for(auto it = m.begin(); it != m.end(); it++){
            maxi = max(maxi, max(abs(it->first->val- it->second.first), abs(it->first->val- it->second.second)));
        }

        return maxi;
    }
};