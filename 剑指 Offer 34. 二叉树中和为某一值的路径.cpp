/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<int> temp;
        backtrace(root,sum,temp);
        return res;
    }
    void backtrace(TreeNode* root,int sum, vector<int> temp)
    {
        if(root==NULL) return ;
        if(root->left==NULL&&root->right==NULL&&sum-root->val==0)
        {
            temp.push_back(root->val);
            res.push_back(temp);
            temp.pop_back();
            return ;
        }
        temp.push_back(root->val);
        backtrace(root->left,sum-root->val,temp);
        backtrace(root->right,sum-root->val,temp);
        temp.pop_back();
    }
};
