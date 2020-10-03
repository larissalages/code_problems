//method1: 
class Solution {
public:
    void preOrder(TreeNode* node,vector<int> &v){
        if(node){
            v.push_back(node->val);
            preOrder(node->left,v);
            preOrder(node->right,v);
        }else{
            v.push_back(0);
        }
    }
    
    void postOrder(TreeNode* node,vector<int> &v){
        if(node){
            postOrder(node->left,v);
            postOrder(node->right,v);
            v.push_back(node->val);
        }else{
            v.push_back(0);
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int> v1,v2;
        if(!root) return true;
        preOrder(root->left,v1);
        postOrder(root->right,v2);
        reverse(v2.begin(),v2.end());
        return v1==v2;
    }
};

//method2:
class Solution {
public:
    bool isSym(TreeNode* left,TreeNode* right){
        if(!left || !right) return left==right;
        if(left->val!=right->val) return false;
        return isSym(left->left,right->right) && isSym(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSym(root->left,root->right);
    }
};