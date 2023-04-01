/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 *
 * https://leetcode.cn/problems/n-queens/description/
 *
 * algorithms
 * Hard (74.11%)
 * Likes:    1529
 * Dislikes: 0
 * Total Accepted:    256.9K
 * Total Submissions: 346.7K
 * Testcase Example:  '4'
 *
 * 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 *
 * 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
 *
 *
 *
 * 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4
 * 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 *
 *
 * 示例 2：
 *
 *
 * 输入：n = 1
 * 输出：[["Q"]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 9
 *
 *
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isvalid(vector<string> &checkerboard, int row, int col) {
        int n = checkerboard.size();
        for (int i = 0; i <= row; i++) {
            if (checkerboard[i][col] == 'Q') {
                return false;
            }
        }
        //检查左上方
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (checkerboard[i][j] == 'Q') {
                return false;
            }
        }
        //检查右上方
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (checkerboard[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }
    /**
     * @description:
     *  路径：checkerboard 中小于 row 的那些行都已经成功放置了皇后
        选择列表：第 row 行的所有列都是放置皇后的选择
        结束条件：row 超过 checkerboard 的最后一行
     * @param {vector<vector<string>>} &result
     * @param {vector<string>} &checkerboard
     * @param {int} row
     * @return {*}
     */
    void track(vector<vector<string>> &result, vector<string> &checkerboard, int row) {
        if (row == checkerboard.size()) {
            result.push_back(checkerboard);
            return;
        }
        for (int i = 0; i < checkerboard[row].size(); i++) {
            if (!isvalid(checkerboard, row, i)) continue;
            checkerboard[row][i] = 'Q';
            track(result, checkerboard, row + 1);
            checkerboard[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // '.' 表示空，'Q' 表示皇后，初始化空棋盘
        vector<string> checkerboard(n, string(n, '.'));
        vector<vector<string>> result;
        track(result, checkerboard, 0);
        return result;
    }
};
// @lc code=end
