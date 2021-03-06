class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        /*
        给定三个字符串 s1, s2, s3, 
        验证 s3 是否是由 s1 和 s2 交错组成的。
        输入：s1 = "aabcc", s2 = "dbbca", s3 = "aa dbbc bc a c"
        输出：true
        输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
        输出：false

        p[i][j]表示s1[0~i-1]和s2[0~j-1]能否交错组成s3[0~i+j-1]。 
        想好边缘条件，字符串涉及子串匹配啥的统统dp完事。
        dp[i][j]=dp[i-1][j]&&s1[i-1]==s3[i+j-1] || dp[i][j-1]&&s2[j-1]==s3[i+j-1]
        */
        if(s1.size()+s2.size()!=s3.size()) return false;
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1));
        dp[0][0] = true;
        for(int i=1;i<=n1;++i)
        {
            dp[i][0] = dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n2;++i)
        {
            dp[0][i] = dp[0][i-1]&&(s2[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n1;i++)
        {
            for(int j=1;j<=n2;j++)
            {
                dp[i][j] = dp[i-1][j]&&s1[i-1]==s3[i-1+j]||dp[i][j-1]&&s2[j-1]==s3[i-1+j];
            }
        }
        return dp[n1][n2];
    }
};
