/*
 * @Author: Jack
 * @Date: 2022-09-18 22:21:42
 * @LastEditTime: 2022-09-19 18:55:23
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/18.四数之和.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode.cn/problems/4sum/description/
 *
 * algorithms
 * Medium (38.33%)
 * Likes:    1364
 * Dislikes: 0
 * Total Accepted:    365.8K
 * Total Submissions: 956.4K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target
 * 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c],
 * nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
 *
 *
 * 0 <= a, b, c, d < n
 * a、b、c 和 d 互不相同
 * nums[a] + nums[b] + nums[c] + nums[d] == target
 *
 *
 * 你可以按 任意顺序 返回答案 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [2,2,2,2,2], target = 8
 * 输出：[[2,2,2,2]]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 200
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 *
 *
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] >= 0 && nums[k] > target)
                break;
            if (k > 0 && nums[k] == nums[k - 1])  //第一位去重
                continue;
            for (int i = k + 1; i < nums.size(); i++) {
                if ((nums[k] + nums[i]) > target && (nums[k] + nums[i]) >= 0)
                    break;
                if (i > k + 1 && nums[i] == nums[i - 1])  //第二位去重
                    continue;
                //定义左右指针
                int left = i + 1;
                int right = nums.size() - 1;

                while (left < right) {
                    //注意数据的范围 定义long类型
                    if ((long)nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    } else if ((long)nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    } else {
                        //先将初步结果保存再去重
                        result.push_back(vector<int>({nums[k], nums[i], nums[left], nums[right]}));

                        while (left < right && nums[left] == nums[left + 1])  // left去重
                            left++;
                        while (left < right && nums[right] == nums[right - 1])  // right去重
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end
