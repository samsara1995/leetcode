/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
              1
            /  \
           /    \
          2      2
         / \    / \
        3  4   4   3

 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return 1;
        return dfs(root->left,root->right);
    }
    bool dfs(TreeNode * left,TreeNode* right)
    {
        if(left==NULL&&right==NULL) return true;
        if(left== NULL || right == NULL|| left->val != right->val) return false;
        return dfs(left->left,right->right)&&dfs(left->right,right->left);

    }
};
