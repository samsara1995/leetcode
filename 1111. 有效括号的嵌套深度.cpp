/*
“你需要从中选出任意一组有效括号字符串 A 和 B，使 max(depth(A), depth(B)) 的可能取值最小”。
这句话其实相当于让A字符串和B字符串的depth尽可能的接近。
为什么呢？因为seq对应的栈上，每个左括号都对应一个深度，
而这个左括号，要么是A的，要么是B的。所以，栈上的左括号只要按奇偶分配给A和B就可以啦！

知道如何计算嵌套深度，问题就很简单了：只要在遍历过程中，我们保证栈内一半的括号属于序列 A，
一半的括号属于序列 B，那么就能保证拆分后最大的嵌套深度最小，
是当前最大嵌套深度的一半。

要实现这样的对半分配，我们只需要把奇数层的 ( 分配给 A，偶数层的 ( 分配给 B 即可。
对于上面的例子，我们将嵌套深度为 1 和 3 的所有括号 (()) 分配给 A，
嵌套深度为 2 的所有括号 ()()() 分配给 B。

\
*/

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res;
        int st=0;
        for (int i =0;i<seq.size();i++)
        {
            if(seq[i]=='(')
            {
                st++;
                res.push_back(st%2);//奇数分给A，偶数分给B

            }
            else 
            {
                res.push_back(st%2);
                st--;
            }
        }
        return res;
    }
};
