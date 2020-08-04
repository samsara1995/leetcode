/**
剑指 Offer 54. 二叉搜索树的第k大节点
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
    int num=0;
    int kthLargest(TreeNode* root, int &k) {
        if(root==NULL) return 0;
        int right= kthLargest(root->right,k);
        //int left= kthLargest(root->left,k);
        k--;
        if(k==0) num=root->val;
        //int right= kthLargest(root->right,k);
        int left= kthLargest(root->left,k);
        return num;

    }
};
