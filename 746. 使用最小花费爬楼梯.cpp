class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        /*
        数组的每个索引作为一个阶梯，第 i个阶梯对应着一个非负数的体力花费值 cost[i](索引从0开始)。

每当你爬上一个阶梯你都要花费对应的体力花费值，然后你可以选择继续爬一个阶梯或者爬两个阶梯。

您需要找到达到楼层顶部的最低花费。在开始时，你可以选择从索引为 0 或 1 的元素作为初始阶梯
    dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i])
    cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
        */
        if(cost.size()==2)
        {
            return min(cost[0],cost[1]);
        }
            vector<int> dp(cost.size()+1,0);
            dp[0]=cost[0];
            dp[1]=cost[1];
            for ( int i =2;i<cost.size();i++)
            {
                dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i]);

            }
            return min(dp[cost.size()-1],dp[cost.size()-2]);
    
    }
};
