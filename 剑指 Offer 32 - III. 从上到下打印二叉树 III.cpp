/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。

 
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
  [3],
  [20,9],
  [15,7]

 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
        {
            return res;
        }
        queue<TreeNode* > qu;
        qu.push(root);
        bool isLeft = false;
        while(!qu.empty())
        {
            int n=qu.size();
            vector<int> temp;
            for (int i =0;i<n;i++)
            {
                TreeNode* tempnode=qu.front();
                qu.pop();
                temp.push_back(tempnode->val);
                if(tempnode->left) qu.push(tempnode->left);
                if(tempnode->right) qu.push(tempnode->right);
            }
            isLeft = !isLeft;
            if(!isLeft){
                res.push_back(vector<int>(temp.rbegin(), temp.rend()));
            }
            else res.push_back(temp);
        }
        return res;
    }
};
