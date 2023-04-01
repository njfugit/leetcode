/*
 * @Author: Jack
 * @Date: 2022-09-18 00:54:59
 * @LastEditTime: 2022-10-03 12:39:30
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/242.有效的字母异位词.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 *
 * https://leetcode-cn.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.63%)
 * Likes:    661
 * Dislikes: 0
 * Total Accepted:    492.6K
 * Total Submissions: 750.5K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 *
 * 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 *
 *
 * 示例 2:
 *
 *
 * 输入: s = "rat", t = "car"
 * 输出: false
 *
 *
 *
 * 提示:
 *
 *
 * 1
 * s 和 t 仅包含小写字母
 *
 *
 *
 *
 * 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 *
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(26, 0);
        for (size_t i = 0; i < s.size(); i++) {
            a[s[i] - 'a']++;
        }
        for (size_t i = 0; i < t.size(); i++) {
            a[t[i] - 'a']--;
        }

        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
