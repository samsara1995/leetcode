class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        /*
        有两个容量分别为 x升 和 y升 的水壶以及无限多的水。
        请判断能否通过使用这两个水壶，从而可以得到恰好 z升 的水？
        如果可以，最后请用以上水壶中的一或两个来盛放取得的 z升 水。

        你允许：
        装满任意一个水壶
        清空任意一个水壶
        从一个水壶向另外一个水壶倒水，直到装满或者倒空
        示例 1: (From the famous "Die Hard" example)

        输入: x = 3, y = 5, z = 4
        输出: True
        输入: x = 2, y = 6, z = 5
        输出: False

        解答：
        因此，我们可以认为每次操作只会给水的总量带来 x 或者 y 的变化量。
        因此我们的目标可以改写成,找到一对整数 a, b,使得 ax+by=z。
        而贝祖定理告诉我们，ax+by=z 有解当且仅当 z 是 x,y 的最大公约数的倍数。
        因此我们只需要找到 x,y 的最大公约数并判断 z 是否是它的倍数即可。
        */
        return !z || !((x + y < z) || (z % std::gcd(x, y)));

    }
};
