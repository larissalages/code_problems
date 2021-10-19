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
    
    void in_order(TreeNode* root, vector<TreeNode*>& in){
        if(root == NULL) return;
        in.push_back(root);
        in_order(root->left, in);
        in_order(root->right, in);
    }
    
    void flatten(TreeNode* root) {
        vector<TreeNode*> inorder;
        in_order(root, inorder);
        inorder.push_back(NULL);
        for(int i=0; i<inorder.size()-1;i++){
            inorder[i]->left = NULL;
            inorder[i]->right = inorder[i+1];
        }
        root = inorder[0];
    }
};