 class Solution {
public:
/*
     5
    / \
   2   6
  / \
 1   3

输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
输入: [1,6,3,2,5]
输出: false
输入: [1,3,2,6,5]
输出: true
*/
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size()==0) return 1;
        return dfs(postorder,0,postorder.size()-1);
    }
    bool dfs(vector<int>& postorder,int left, int right)
    {
        if(left>=right) return true;
        int rootval=postorder[right];
        int k =left;
        while(k<right&&postorder[k]<rootval) k++;
        for (int i = k; i < right; i++){ 
            if (postorder[i] < rootval) return false;
        }
        if(!dfs(postorder,left,k-1)) return false;
        if(!dfs(postorder,k,right-1)) return false;
        return true;

    }
};
