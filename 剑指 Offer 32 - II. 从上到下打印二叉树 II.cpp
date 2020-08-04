/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;

        queue<TreeNode*> qu;
        qu.push(root);
    
        while(!qu.empty())
        {
            vector<int> tmpstr;
            int n=qu.size();
            for (int i=0;i<n;i++)
            {
              
                TreeNode* temp=qu.front();
                tmpstr.push_back(temp->val);
                cout<<temp->val<<" ";
                qu.pop();
                if(temp->left)
                {
                    qu.push(temp->left);
                }
                if(temp->right)
                {
                    qu.push(temp->right);
                }
           
            }
            cout<<endl;
            res.push_back(tmpstr);
        } 
        return res;
    }
};
