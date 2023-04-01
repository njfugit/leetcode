/*
 * @Author: Jack
 * @Date: 2022-09-20 15:45:18
 * @LastEditTime: 2022-09-21 12:55:34
 * @LastEditors: your name
 * @FilePath: /.leetcode/459.重复的子字符串.cpp
 */
/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 *
 * https://leetcode-cn.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (51.09%)
 * Likes:    784
 * Dislikes: 0
 * Total Accepted:    141.6K
 * Total Submissions: 277K
 * Testcase Example:  '"abab"'
 *
 * 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "abab"
 * 输出: true
 * 解释: 可由子串 "ab" 重复两次构成。
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "aba"
 * 输出: false
 *
 *
 * 示例 3:
 *
 *
 * 输入: s = "abcabcabcabc"
 * 输出: true
 * 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 *
 * 1 <= s.length <= 10^4
 * s 由小写英文字母组成
 *
 *
 */

/* //移动匹配 s+s 掐头去尾 里面是否还有s
string ss = s + s;
ss.erase(ss.begin());
ss.erase(ss.end() - 1);
if (ss.find(s) != string::npos)
    return true;
return false;   */

// @lc code=start
#include <string>
using namespace std;
class Solution {
public:
    void getnext(int *next, const string &s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int next[s.size()];
        getnext(next, s);
        int len = s.size();
        if (next[len - 1] != 0 && (len % (len - (next[len - 1]))) == 0) {
            return true;
        }
        return false;
    }
};
// @lc code=end
