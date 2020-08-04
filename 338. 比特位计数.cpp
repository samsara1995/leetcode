class Solution {
public:
    vector<int> countBits(int num) {
        /*
        给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，
        计算其二进制数中的 1 的数目并将它们作为数组返回。
        输入: 2 :0 1 2
        输出: [0,1,1]

        输入: 5 :0 1 2 3 4 5
        输出: [0,1,1,2,1,2]
        很简单啊，不用多说，设dp[i]为i的二进制形式的1的个数，
        i是奇数时，dp[i]=dp[i-1]+1,因为i是在i-1的二进制数上加了个1啊；
        i是偶数时，dp[i]=dp[i/2],因为i就是把i/2往左移（是数左移，末尾补0）得到的，
        所以1的个数没变


        */
        vector<int> dp(num+1,0);
        if(num==0) return dp;
        dp[0]=0;
        dp[1]=1;
        if(num==1) return dp;
        for ( int i=1;i<=num;i++)
        {
            if(i%2==1)
            {
                dp[i]=dp[i-1]+1;
            }
            else {
                dp[i]=dp[i/2];
            }
        }
        return dp;
    }
};
