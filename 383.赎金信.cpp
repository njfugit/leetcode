/*
 * @Author: Jack
 * @Date: 2022-09-18 15:17:58
 * @LastEditTime: 2022-09-18 16:37:57
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/383.赎金信.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 *
 * https://leetcode-cn.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (61.47%)
 * Likes:    484
 * Dislikes: 0
 * Total Accepted:    237.7K
 * Total Submissions: 388K
 * Testcase Example:  '"a"\n"b"'
 *
 * 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
 *
 * 如果可以，返回 true ；否则返回 false 。
 *
 * magazine 中的每个字符只能在 ransomNote 中使用一次。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：ransomNote = "a", magazine = "b"
 * 输出：false
 *
 *
 * 示例 2：
 *
 *
 * 输入：ransomNote = "aa", magazine = "ab"
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：ransomNote = "aa", magazine = "aab"
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote 和 magazine 由小写英文字母组成
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // //使用数组效率更高
        // unordered_map<char, int> hashmap;

        // for (char a : ransomNote)
        // {
        //     hashmap[a]++;
        // }
        // for (char b : magazine)
        // {
        //     if (hashmap[b])
        //     {

        //         hashmap[b]--;
        //     }
        // }
        // for (auto iter = hashmap.begin(); iter != hashmap.end(); iter++)
        // {
        //     if (iter->second != 0)
        //         return false;
        // }
        // return true;
        vector<int> record(26, 0);
        if (ransomNote.size() > magazine.size())
            return false;

        for (int i = 0; i < magazine.size(); i++)
        {
            record[magazine[i] - 'a']++; //统计原来的字符串中的字符个数
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            record[ransomNote[i] - 'a']--;
            if (record[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end
