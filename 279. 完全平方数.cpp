class Solution {
public:
    int numSquares(int n) {
        /*
        给定正整数 n，找到若干个完全平方数
        （比如 1, 4, 9, 16, ...）
        使得它们的和等于 n。你需要让组成和的完全平方数的个数最少.
        输入: n = 12 输出: 3 
        解释: 12 = 4 + 4 + 4.
        输入: n = 13 输出: 2
        解释: 13 = 4 + 9.
        解答：
        dp[i]=组成i需要多少个完全平方数
        dp[i]=min(dp[i-1*1],dp[i-2*2],dp[i-3*3].....dp[i-k*k])
        其中，k*k<=n
        */
        vector<int> dp(n+2,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for (int i =1;i<=n;i++)
        {
            int minres=INT_MAX;
            for ( int j=1;j*j<=i;j++)
            {
                minres=min (minres,dp[i-j*j]);
            }
            dp[i]=minres+1;

        }
        return dp[n];
    }
};
