class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    /*
    输入: "abcabcbb"
          abc
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
    示例 2:

    输入: "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
    示例 3:

    输入: "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

    思路：滑动窗口

    */
     if(s.size()==0)return 0;
        unordered_set<char> dic;
        int l=0,r=0,res=0;
        while(r<s.size())
        {
            while(dic.find(s[r])!=dic.end())
                    dic.erase(s[l++]);       
            dic.insert(s[r++]);
            res=max(res,r-l);          
        }
        return res;
    }
};
