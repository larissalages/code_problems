//recursive method: 
class Solution {
public:
    void traverse(TreeNode* root,vector<int> &v){
        if(root){
            traverse(root->left,v);
            v.push_back(root->val);
            traverse(root->right,v);
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        traverse(root,v);
        return v;
    }
};

//stack method:
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> v;
        stack<TreeNode*> s;
        auto curr=root;
        while(curr || !s.empty( )){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            v.push_back(curr->val);
            curr=curr->right;
        }
        return v;
    }
};

//Morris Traversal:
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> v;
        auto curr=root;
        while(curr){
            if(curr->left==NULL){
                v.push_back(curr->val);
                curr=curr->right;
            }else{
                auto pre=curr->left;
                while(pre->right && pre->right!=curr) pre=pre->right;
                if(!pre->right){
                    pre->right=curr;
                    curr=curr->left;
                }else{
                    pre->right=NULL;
                    v.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return v;
    }
};