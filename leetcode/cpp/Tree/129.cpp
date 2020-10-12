//Sum root to leaf numbers

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
    int dfs(int parent, TreeNode* root){
        int cur = parent*10+root->val;
        int sum = 0;
        if(root->left == NULL && root->right == NULL)
            return cur;
        if(root->left!=NULL)
            sum = dfs(cur,root->left);
        if(root->right!=NULL)
            sum+=dfs(cur,root->right);
        return sum;
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        return dfs(0,root);
    }
};