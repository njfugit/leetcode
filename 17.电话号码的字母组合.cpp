/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (57.79%)
 * Likes:    2163
 * Dislikes: 0
 * Total Accepted:    590.7K
 * Total Submissions: 1M
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：digits = ""
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const string letterMap[10] = {
        "",      // 0
        "",      // 1
        "abc",   // 2
        "def",   // 3
        "ghi",   // 4
        "jkl",   // 5
        "mno",   // 6
        "pqrs",  // 7
        "tuv",   // 8
        "wxyz",  // 9
    };

    vector<string> result;
    string s;
    void trackback(const string& digits, int index) {  // index表示遍历到第几个数字
        if (index == digits.size()) {
            result.push_back(s);
            return;
        }

        int digit = digits[index] - '0';//字符串转成数字
        string letters = letterMap[digit];
        for (int i = 0; i < letters.size();i++){
            s.push_back(letters[i]);
            trackback(digits, index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        result.clear();
        s.clear();
        if (digits.size() == 0) return result;

        trackback(digits, 0);
        return result;
    }
};
// @lc code=end
