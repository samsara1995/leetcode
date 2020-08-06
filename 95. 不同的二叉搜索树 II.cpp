**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };


 给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。

 

示例：

输入：3
输出：
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释：
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0) return {};
        return dfs(1,n);
    }
    vector<TreeNode*> dfs(int start,int end)
    {
        if(start > end) return {NULL};
        vector<TreeNode*> res;
        //枚举可行的跟结点
        for (int i =start;i<=end;i++)
        {
            vector<TreeNode*> left=dfs(start,i-1);
            vector<TreeNode*> right=dfs(i+1,end);
            //// 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
            for (auto& left_:left)
            {
                for(auto& right_:right)
                {
                    TreeNode* currTree = new TreeNode(i);
                    currTree->left = left_;
                    currTree->right = right_;
                    res.emplace_back(currTree);
                }
            }
        }
        return res;
    }
};
