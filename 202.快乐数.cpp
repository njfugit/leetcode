/*
 * @Author: Jack
 * @Date: 2022-09-18 13:53:02
 * @LastEditTime: 2022-09-18 14:16:32
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/202.快乐数.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (63.15%)
 * Likes:    1069
 * Dislikes: 0
 * Total Accepted:    301K
 * Total Submissions: 476.6K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 *
 * 「快乐数」 定义为：
 *
 *
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 *
 *
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 2
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 2^31 - 1
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int getSum(int n)
    {
        int sum = 0;
        //关于多位数拆开求和
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }

        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<int> set;
        while (true)
        {
            int sum = getSum(n);
            if (sum == 1)
                return true;
            if (set.find(sum) != set.end())
            {
                return false;
            }
            else
            {
                set.insert(sum);
            }
            n = sum;
        }
    }
};
// @lc code=end
