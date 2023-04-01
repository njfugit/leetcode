/*
 * @Author: Jack
 * @Date: 2022-09-22 15:58:27
 * @LastEditTime: 2022-09-23 01:01:15
 * @LastEditors: your name
 * @FilePath: /.leetcode/1047.删除字符串中的所有相邻重复项.cpp
 */
/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 *
 * https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string/description/
 *
 * algorithms
 * Easy (72.69%)
 * Likes:    438
 * Dislikes: 0
 * Total Accepted:    183.4K
 * Total Submissions: 252.1K
 * Testcase Example:  '"abbaca"'
 *
 * 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
 *
 * 在 S 上反复执行重复项删除操作，直到无法继续删除。
 *
 * 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
 *
 *
 *
 * 示例：
 *
 * 输入："abbaca"
 * 输出："ca"
 * 解释：
 * 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串
 * "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= S.length <= 20000
 * S 仅由小写英文字母组成。
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        // stack<char> st;
        // for (int i = 0; i < s.size(); i++) {
        //     if (st.empty() || st.top() != s[i]) {
        //         st.push(s[i]);
        //     } else {
        //         st.pop();  // st.top() == s[i]
        //     }
        // }
        // string result = "";
        // while (!st.empty()) {
        //     result += st.top();
        //     st.pop();
        // }
        // reverse(result.begin(), result.end());
        // return result;
    
        string result = "";
        for (char a : s) {
            if (result.empty() || a != result.back()) {
                result.push_back(a);
            } else {
                result.pop_back();
            }
        }
        return result;
    }
};
// @lc code=end
