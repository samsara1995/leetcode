class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        /*
        给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，
        找到矩阵中第 k 小的元素。
        请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
        [ 1,  5,  9],
        [10, 11, 13],
        [12, 13, 15]
         k = 8,
        返回 13。
        二分： 11 (5<8)[11前面有5个数，比8小]->left=mid+1;
        */
        int n=matrix.size()-1;
        int left=matrix[0][0];
        int right=matrix[n][n];
        while(left<right)
        {
            int mid=left+(right-left)/2;
            int lenn=count_num(matrix,mid,n);
            if(lenn<k)//K 在前半部分
            {
                left=mid+1;
            }
            else {
                right=mid;
            }
        }
        return right;
    }
    int count_num(vector<vector<int>>& matrix,int mid,int n)
    {
        int x = n, y = 0, count = 0;
        while(x >= 0 && y <= n) {
            if(matrix[x][y] <= mid) {
                count += x + 1;
                ++ y;
            }else {
                -- x;
            }
        }
        return count;

    }
};
