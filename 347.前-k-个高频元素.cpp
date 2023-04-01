/*
 * @Author: Jack
 * @Date: 2022-09-24 12:40:14
 * @LastEditTime: 2022-09-24 14:49:15
 * @LastEditors: your name
 * @FilePath: /.leetcode/347.前-k-个高频元素.cpp
 */
/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 *
 * https://leetcode-cn.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.31%)
 * Likes:    1330
 * Dislikes: 0
 * Total Accepted:    353K
 * Total Submissions: 557.3K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [1,1,1,2,2,3], k = 2
 * 输出: [1,2]
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1], k = 1
 * 输出: [1]
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * k 的取值范围是 [1, 数组中不相同的元素的个数]
 * 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 *
 *
 *
 *
 * 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
 *
 */

// @lc code=start
// 注意const  map和unordered_map的元素类型为std::pair<const key_type, mapped_type>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {  //统计频次
            hashmap[nums[i]]++;
        }
        auto lessheap = [](const pair<int, int> &map1, const pair<int, int> &map2) {
            return map1.second > map2.second;
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(lessheap)>
            pq(lessheap);

        for (const pair<int, int> &map : hashmap) {
            pq.push(map);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pq.top().first;
            pq.pop();
        }
        return result;
    }
};
// @lc code=end
