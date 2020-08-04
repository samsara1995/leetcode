/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 给定一个二叉树，返回所有从根节点到叶子节点的路径。

说明: 叶子节点是指没有子节点的节点。

   1
 /   \
2     3
 \
  5

输出: ["1->2->5", "1->3"]


 */
class Solution {
public:
    vector<string> res;

    vector<string> binaryTreePaths(TreeNode* root) {
        string temp;
        if(root==NULL) return res;
        dfs(root,temp);
        return res;
        
    }
    void dfs(TreeNode * root,string temp)
    {
        if(root==NULL) return;
    
        if(root->left==NULL&&root->right==NULL)//leaf
        {
            temp+=to_string(root->val);
            res.push_back(temp);
            return ;
        }
        else{
            temp+=to_string(root->val);
        }
        if(root->left) dfs(root->left,temp+"->");
        if(root->right) dfs(root->right,temp+"->");
        return ;
    }
};
