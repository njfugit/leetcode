/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.02%)
 * Likes:    2154
 * Dislikes: 0
 * Total Accepted:    534K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 *
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 *
 * 你可以认为每种硬币的数量是无限的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 示例 2：
 *
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /* vector<int> mem;
    int dp(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount < 0) return -1;
        if (mem[amount] != 0) return mem[amount];
        int res = INT_MAX;
        for (auto coin : coins) {
            int sub = dp(coins, amount - coin);
            if (sub == -1) continue;
            res = min(res, 1+sub);
        }
        mem[amount] = (res == INT_MAX) ? -1 : res;
        return mem[amount];
        
    } */
    int coinChange(vector<int>& coins, int amount) {
        /* mem.resize(amount + 1);
        return dp(coins, amount);  */

        vector<int> dp(amount + 1, amount + 1); //dp表示i金额时，至少dp[i]个硬币
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            for(int &coin : coins){
                if(i - coin < 0) continue;

                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};
// @lc code=end
