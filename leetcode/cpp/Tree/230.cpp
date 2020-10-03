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

//method1: inorder traversal
class Solution {
public:
    void inorder(TreeNode* node,vector<int> &v){
        if(node){
            inorder(node->left,v);
            v.push_back(node->val);
            inorder(node->right,v);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        inorder(root,v);
        return v[k-1];
    }
};

//method2: using Morris Traversal
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root,*pre;
        int ans;
        while(curr){
            if(curr->left==NULL){
                k--;
                if(k==0) ans=curr->val;
                curr=curr->right;
            }else{
                pre=curr->left;
                while(pre->right && pre->right!=curr) pre=pre->right;
                if(!pre->right){
                    //this indicates we have pointer to the root element from where we should continue the traversing, so for inorder we jump to this root element,
                    //& then traverse the right subtree from there.
                    //to leave the tree as we found, set right element to the NULL again & jumps to root(the current root, parent of the current subtree) & continue.
                    pre->right=curr;
                    curr=curr->left;
                }else{  //connecting rightmost element of the left subtree to current element, so we know where to continue when we finish with the 
                    //left subtree, basically to maintain inorder.
                    //in inorder traversal after traversing all left elements root element should be traverse and then the rest of the right subtree elements.
                    //so for that in morris traversal we connect rightmost element to the root(of current subtree).
                    pre->right=NULL;
                    k--;
                    if(k==0) ans=curr->val;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};