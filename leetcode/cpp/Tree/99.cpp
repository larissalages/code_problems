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
class Solution
{
public:
    vector<pair<int, TreeNode *>> v;
    void ans(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        ans(root->left);
        v.push_back({root->val, root});
        ans(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        ans(root);
        vector<int> b;
        for (int i = 0; i < v.size(); i++)
        {
            b.push_back(v[i].first);
        }
        sort(b.begin(), b.end());
        int check = 0;
        TreeNode *change1 = NULL;
        TreeNode *change2 = NULL;
        for (int i = 0; i < b.size(); i++)
        {
            if (v[i].first != b[i] && check == 0)
            {
                change1 = v[i].second;
                check++;
            }
            if (v[i].first != b[i] && check == 1)
            {
                change2 = v[i].second;
            }
        }
        int a = change1->val;
        change1->val = change2->val;
        change2->val = a;
        return;
    }
};
