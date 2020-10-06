class Solution {
public:
            vector<int> v;
    void tree1(TreeNode *root)
    {
        if(root!=NULL)
        {
            v.push_back(root->val);
            tree1(root->left);
             tree1(root->right);
            
        }
    }
    void tree2(TreeNode *root)
    {
        if(root!=NULL)
        {
            v.push_back(root->val);
            tree2(root->left);
             tree2(root->right);
            
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {

        tree1(root1);
        tree2(root2);
        sort(v.begin(),v.end());
        return v;
        
    }
};
