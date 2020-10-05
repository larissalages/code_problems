//method1: good old recursion
class Solution {
public:
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q) return true;
    if(!p || !q) return false;
    bool c1=isSameTree(p->left,q->left);
    bool c2=isSameTree(p->right,q->right);
    bool c3=(p->val==q->val);
    return c1 && c2 &&c3;
    }
};

//method2: Level Order Traversal // BFS
class Solution {
public:
    void levelOrderTraversal(TreeNode* root,vector<int> &v){
        int h=height(root);
        for(int i=1;i<=h;i++) traverseLevel(root,i,v);
    }
    
    void traverseLevel(TreeNode* node,int level,vector<int> &v){
        if(level==1){
            if(node) v.push_back(node->val);
            else v.push_back(0);
        }
        else{
            if(node){
                traverseLevel(node->left,level-1,v);
                traverseLevel(node->right,level-1,v);
            }
        }
    }
    
    int height(TreeNode* node){
        if(!node) return 0;
        return max(height(node->left),height(node->right))+1;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> v1,v2;
        levelOrderTraversal(p,v1);
        levelOrderTraversal(q,v2);
        return v1==v2;
    }
};