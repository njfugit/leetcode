/*
 * @Author: Jack
 * @Date: 2021-11-30 00:40:56
 * @LastEditTime: 2022-09-18 14:55:10
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/1.两数之和.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // int n = nums.size();

        // for(int i = 0; i < n; ++i){
        //     for(int j = i+1; j < n; ++j){
        //         if(nums[i] + nums[j] == target){
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++)
        {
            auto iter = hashmap.find(target - nums[i]);
            if (iter != hashmap.end())
            {
                return {iter->second, i};
            }

            hashmap.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
// @lc code=end
