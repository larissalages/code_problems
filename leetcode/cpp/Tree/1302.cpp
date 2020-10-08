/**
 * Problem link: https://leetcode.com/problems/deepest-leaves-sum/
 * Solution:
 * (1) If the current leaf node depth is greater than the maximum leaf depth found till now, set maximum depth as current leaf depth and initialize sum.
 * (2) If the current leaf node depth is less than the maximum leaf depth found till now, dont do anything.
 * (3) If the current leaf node depth is equal to the maximum leaf depth found till now, increase the sum.
 *
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
    
    int mx_d, ans;
    
    void dfs(TreeNode *node, int depth) {
        
        if (node == NULL) return;
        
        if (node->right == NULL && node->left == NULL) {
            
            if (depth == mx_d) {
                
                ans += node->val;
                
            } else if (depth > mx_d) {
                
                mx_d = depth;
                ans = node->val;
                
            } else if (depth < mx_d) {
                
                return;
            }
        }
        
        if (node->right != NULL) dfs(node->right, depth+1);
        
        if (node->left != NULL) dfs(node->left, depth+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        
        mx_d = 0;
        ans = 0;
        
        dfs(root, 0);
        
        return ans;
    }
};
