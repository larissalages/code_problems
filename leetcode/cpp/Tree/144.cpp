class Solution {
public:
    void preorderTraversal(TreeNode* node,vector<int> &pre){
        if(!node) return;
        pre.push_back(node->val);
        preorderTraversal(node->left,pre);
        preorderTraversal(node->right,pre);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        preorderTraversal(root,pre);
        return pre;
    }
};