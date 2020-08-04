class Solution {
public:
    string getPermutation(int n, int k) {
        /*
        给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
        按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
        "123"  1234 4*3*2*1 9/(3!)=1 9-(3!)=9-6=3 3/(2!)=1 
        "132"  1243       1234  2                 134 3
        "213"  1324
        "231"  1342
        "312"  1423
        "321"  1432
               2...
        给定 n 和 k，返回第 k 个排列。
        给定 n 的范围是 [1, 9]。
        给定 k 的范围是[1,  n!]。

        输入: n = 3, k = 3
        输出: "213"

        输入: n = 4, k = 9
        输出: "2314"
        思路；回溯法超时
        */
        vector<int> factor(n+1,1);
        vector<int> cannum;
        factor[0]=1;
        int fact=1;
        //构造阶乘的函数
        for (int i =1;i<=n;i++)
        {
            cannum.push_back(i);  
            fact*=i;
            factor[i]=fact;
        }
        string s;
        k--;
        for(int i =n-1;i>=0;i--)
        {
            int index=k/factor[i];
            //cout<<index<<" ";
            int num=cannum[index];
            cannum.erase(std::begin(cannum)+index);
            cout<<num<<endl;
            s.push_back(num+'0');
            k-=index*factor[i];
        }
        
        return s；
    }
};
