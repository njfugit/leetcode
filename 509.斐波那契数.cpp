/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 *
 * https://leetcode.cn/problems/fibonacci-number/description/
 *
 * algorithms
 * Easy (66.55%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    461.4K
 * Total Submissions: 693.3K
 * Testcase Example:  '2'
 *
 * 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
 * 
 * 
 * F(0) = 0，F(1) = 1
 * F(n) = F(n - 1) + F(n - 2)，其中 n > 1
 * 
 * 
 * 给定 n ，请计算 F(n) 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：1
 * 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3
 * 输出：2
 * 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：n = 4
 * 输出：3
 * 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 <= n <= 30
 * 
 * 
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int help(vector<int> &mem, int n){
        if (n == 0 || n == 1) return n;
        if (mem[n] != 0) return mem[n];
        mem[n] = help(mem, n - 1) + help(mem, n - 2);
        return mem[n];
    }
    int fib(int n) {
        /* if (n == 0 || n == 1) return n;//dp表，压缩成一维
        int f1 = 0, f2 = 1;
        for (int i = 2; i <= n;i++){
            int fn = f1 + f2;
            f1 = f2;
            f2 = fn;
        }
        return f2; */
        vector<int> mem(n + 1, 0);
        return help(mem, n);
    }
};
// @lc code=end

