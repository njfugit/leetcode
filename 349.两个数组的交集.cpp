/*
 * @Author: Jack
 * @Date: 2022-09-18 12:06:52
 * @LastEditTime: 2022-09-18 12:37:18
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/349.两个数组的交集.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 *
 * https://leetcode-cn.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (74.27%)
 * Likes:    622
 * Dislikes: 0
 * Total Accepted:    350.7K
 * Total Submissions: 472K
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出：[9,4]
 * 解释：[4,9] 也是可通过的
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 */

// @lc code=start
// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result;
        unordered_set<int> num_set(nums1.begin(), nums1.end()); //将nums1数值存入set中
        for (int num : nums2)
        {
            if (num_set.find(num) != num_set.end())
            {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};
// @lc code=end
