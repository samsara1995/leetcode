class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        /*
        给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
        两个相邻元素间的距离为 1 。
        输入:
        0 0 0
        0 1 0
        1 1 1
        输出:
        0 0 0
        0 1 0
        1 2 1
        思路;从 0 开始BFS
        */
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<int> qi;
        queue<int> qj;
        for ( int i =0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)//add to queue
                {
                    qi.push(i);qj.push(j);
                    visited[i][j]=1;
                }
            }
        }
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};

        while(!qi.empty())
        {
            int i=qi.front();
            qi.pop();
            int j=qj.front();
            qj.pop();
            for (int k=0;k<4;k++)
            {
                int nx=i+dx[k];
                int ny=j+dy[k];
                if(nx<0 || nx>=m || ny<0 || ny>=n||visited[nx][ny]==1) continue;
                qi.push(nx);
                qj.push(ny);
                matrix[nx][ny]=matrix[i][j]+1;
                visited[nx][ny]=1;

            }

        }
        return matrix;
    }
};
