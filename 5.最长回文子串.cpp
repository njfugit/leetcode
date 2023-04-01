/*
 * @Author: Jack
 * @Date: 2021-12-14 23:21:21
 * @LastEditTime: 2022-03-31 00:48:34
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/5.最长回文子串.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (35.77%)
 * Likes:    4460
 * Dislikes: 0
 * Total Accepted:    813.5K
 * Total Submissions: 2.3M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */
#include <iostream>
#include <string>
using namespace std;
// @lc code=start
class Solution
{
public:
    string Palindrome(const string &s, int l, int r)
    {
        while(l >=0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }
    string longestPalindrome(string s)
    {
        string res = "";
        for (int i = 0; i < s.size(); i++)
        {
            string s1 = Palindrome(s, i, i);
            string s2 = Palindrome(s, i, i + 1);
            res = res.length() > s1.length() ? res : s1;
            res = res.length() > s2.length() ? res : s2;
        }
        return res;
    }
};
// @lc code=end
