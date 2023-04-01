/*
 * @Author: Jack
 * @Date: 2022-09-23 12:14:44
 * @LastEditTime: 2022-09-24 01:05:26
 * @LastEditors: your name
 * @FilePath: /.leetcode/239.滑动窗口最大值.cpp
 */
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (50.01%)
 * Likes:    1881
 * Dislikes: 0
 * Total Accepted:    359.8K
 * Total Submissions: 718.7K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k
 * 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回 滑动窗口中的最大值 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
 * 输出：[3,3,5,5,6,7]
 * 解释：
 * 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1], k = 1
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
//单调队列 deque
class Solution {
private:
    class Myqueue {
    public:
        deque<int> dq;

        void push(int val) {
            while (!dq.empty() && val > dq.back()) {
                dq.pop_back();
            }
            dq.push_back(val);
        }
        void pop(int val) {
            if (!dq.empty() && val == dq.front()) {
                dq.pop_front();
            }
        }
        int front() {
            return dq.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue q;
        vector<int> result;
        for (int i = 0; i < k; i++) {  //前k个元素放入单调队列中
            q.push(nums[i]);
        }
        result.push_back(q.front());
        for (int i = k; i < nums.size(); i++) {
            q.pop(nums[i - k]);
            q.push(nums[i]);
            result.push_back(q.front());
        }
        return result;
    }
};
// @lc code=end
