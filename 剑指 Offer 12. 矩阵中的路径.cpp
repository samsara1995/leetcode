/*
剑指 Offer 12. 矩阵中的路径
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

[["a","b","c","e"],
["s","f","c","s"],
["a","d","e","e"]]

但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 

示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
提示：

1 <= board.length <= 200
1 <= board[i].length <= 200

*/


class Solution {
public:
    int n,m;
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) 
            return word.empty();
        n=board.size();
        m=board[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(dfs(board,i,j,word,0,visited)==1)
                {
                    return true;
                }
            }
        }
        return false;

    }
    bool dfs(vector<vector<char>>& board,int i ,int j ,string word,int index,vector<vector<int>>& visited)
    {
        if(index>=word.size())
        {
            return true;
        }
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word[index]||visited[i][j]==1)
        {
            return false;
        }
        visited[i][j]=1;
        bool res=dfs(board,i,j-1,word,index+1,visited)
                || dfs(board,i,j+1,word,index+1,visited)
                || dfs(board,i-1,j,word,index+1,visited)
                || dfs(board,i+1,j,word,index+1,visited);
        if(res) return true;
        visited[i][j]=0;
        return false;
    }

};
