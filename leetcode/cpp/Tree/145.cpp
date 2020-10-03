//recursive approach
class Solution {
public:
    void postOrderTraversal(TreeNode* node,vector<int> &post){
        if(!node) return;
        postOrderTraversal(node->left,post);
        postOrderTraversal(node->right,post);
        post.push_back(node->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        postOrderTraversal(root,post);
        return post;
    }
};