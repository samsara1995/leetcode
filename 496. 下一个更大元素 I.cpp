class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
        给定两个 没有重复元素 的数组 nums1 和 nums2 ，
        其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。
        nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。
        如果不存在，对应位置输出 -1 。

        输入: nums1 = [4,1,2], nums2 = [1,3,4,2].
        输出: [-1,3,-1]
        解释:
            对于num1中的数字4，你无法在第二个数组中找到下一个更大的数字，因此输出 -1。
            对于num1中的数字1，第二个数组中数字1右边的下一个较大数字是 3。
            对于num1中的数字2，第二个数组中没有下一个更大的数字，因此输出 -1。

        输入: nums1 = [2,4], nums2 = [1,2,3,4].
        输出: [3,-1]
        解释:
            对于 num1 中的数字 2 ，第二个数组中的下一个较大数字是 3 。
            对于 num1 中的数字 4 ，第二个数组中没有下一个更大的数字，因此输出 -1 。

        思路：单调栈:维护一个单调栈，栈中的元素值为递减的
        for(num[i]->入栈)
        如果发现栈中的元素都比num i小，把这些元素弹出，num i放最底下。
        map对；top()->num i  numi是top元素的下一个较大的元素

        */
        vector<int> res;
        stack<int> st;
        map<int ,int> mp;
        for(int i=0;i<nums2.size();i++)
        {
            while(!st.empty()&&nums2[i]>st.top())
            {
                mp[st.top()]=nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while(!st.empty())
        {
            mp[st.top()]=-1;
            st.pop();
        }
        for (int i=0;i<nums1.size();i++)
        {
            res.push_back(mp[nums1[i]]);
        }
        return res;
    }
};
