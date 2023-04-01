/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i = 0; i < nums.size(); ++i){
            auto it = hashtable.find(target - nums[i]);
            /*find 查找key所在的元素。
            - 找到：返回元素的迭代器。通过迭代器的second属性获取值
            - 没找到：返回unordered_map::end*/
            if(it != hashtable.end()){
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

