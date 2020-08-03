/*
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
思路：优先队列
*/


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //堆 优先队列
        using pii=std::pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>> minheap;

        map<int,int> counter;

        for (auto ns:nums)
        {
            ++counter[ns];
        }
        for (auto & x:counter)
        {
            //3 num 4
            minheap.emplace(x.second,x.first);//==push_back
            if(minheap.size()>k)
            {
                minheap.pop();
            }
        }
        vector<int> res;
        while(minheap.empty()==0)
        {
            res.push_back(minheap.top().second);
            minheap.pop();
        }
        return res;
    }
};
