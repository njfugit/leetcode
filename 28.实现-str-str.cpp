/*
 * @Author: Jack
 * @Date: 2022-09-06 01:56:15
 * @LastEditTime: 2022-09-19 20:02:23
 * @LastEditors: your name
 * @FilePath: /.leetcode/28.实现-str-str.cpp
 */
/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 *
 * algorithms
 * Medium (41.44%)
 * Likes:    1574
 * Dislikes: 0
 * Total Accepted:    728.6K
 * Total Submissions: 1.8M
 * Testcase Example:  '"sadbutsad"\n"sad"'
 *
 * 实现 strStr() 函数。
 *
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0
 * 开始）。如果不存在，则返回  -1 。
 *
 * 说明：
 *
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 *
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf()
 * 定义相符。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= haystack.length, needle.length <= 10^4
 * haystack 和 needle 仅由小写英文字符组成
 *
 *
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    //获取next数组
    void getnext(int *next, const string &s) {
        // j表示前缀末尾， i表示后缀末尾
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            //处理前后缀不相同的情况
            // s[i] 与 s[j+1] 不相同，就要找 j+1前一个元素在next数组里的值（就是next[j]）
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];  //向前回退
            }
            if (s[i] == s[j + 1]) {  //若是前后缀相同 i和j都要自加
                j++;
            }
            next[i] = j;  //记录相同前后缀的长度
        }
    }
    int strStr(string haystack, string needle) {
        // base case
        if (needle.size() == 0)
            return 0;
        int next[needle.size()];
        getnext(next, needle);  //得到目标字符串的next数组

        int j = -1;  // j表示目标字符串needle的下标
        for (int i = 0; i < haystack.size(); i++) {
            while (j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];  //不匹配
            }
            if (haystack[i] == needle[j + 1]) {
                j++;  //源字符串与目标字符串匹配的话
            }
            if (j == (needle.size() - 1)) {  //找到匹配到的字符串
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
// @lc code=end
