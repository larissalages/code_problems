class Solution {
public:
    int countNodes(TreeNode* root) {
        return !root? 0: countNodes(root->left)+countNodes(root->right)+1;
    }
};