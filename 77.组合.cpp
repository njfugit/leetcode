/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.23%)
 * Likes:    1175
 * Dislikes: 0
 * Total Accepted:    442.7K
 * Total Submissions: 573.2K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 *
 * 你可以按 任何顺序 返回答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 *
 * 示例 2：
 *
 *
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    void trackback(int n, int k, int startindex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        // for (int i = startindex; i <= n;i++){
        //     path.push_back(i);
        //     trackback(n, k, i + 1);
        //     path.pop_back();
        // }
        for (int i = startindex; i <= (n - (k - path.size()) + 1);i++){
            path.push_back(i);
            trackback(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        trackback(n, k, 1);
        return result;
    }
};
// @lc code=end
