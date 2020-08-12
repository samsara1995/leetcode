/*

输入一个字符串，打印出该字符串中字符的所有排列。

 

你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

 

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
*/


class Solution {
public:
std::vector<std::string> permutation(std::string s) {
    if(s.empty()){
        return {};
    }

    // 对字符串进行排序
    std::sort(s.begin(), s.end());
    std::vector<std::string> res;
    // 标记字符是否遍历过
    std::vector<bool> visit(s.size(), false);
    std::string track;
    backtrack(res, s, track, visit);

    return res;
}

    /*
     * 回溯函数
     * 使用sort函数对字符串排序，使重复的字符相邻，
     * 使用visit数组记录遍历决策树时每个节点的状态，
     * 节点未遍历且相邻字符不是重复字符时，
     * 则将该字符加入排列字符串中，依次递归遍历。
     * */
void backtrack(std::vector<std::string> &res, std::string s, std::string &track, std::vector<bool> &visit) {
    // 回溯结束条件
    if(track.size() == s.size()){
        res.push_back(track);
        return;
    }

    // 选择和选择列表
    for(int i = 0; i < s.size(); i++){
        // 排除不合法的选择
        if(visit[i]){
            continue;
        }

        if(i > 0 && !visit[i-1] && s[i-1] == s[i]){
            continue;
        }
        visit[i] = true;

        // 做选择
        track.push_back(s[i]);
        // 进入下一次决策树
        backtrack(res, s, track, visit);
        // 撤销选择
        track.pop_back();
        visit[i] = false;
    }
}
};
