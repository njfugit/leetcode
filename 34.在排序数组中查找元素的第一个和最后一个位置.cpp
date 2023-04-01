/*
 * @Author: Jack
 * @Date: 2022-03-23 20:15:14
 * @LastEditTime: 2022-03-28 23:48:23
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/34.在排序数组中查找元素的第一个和最后一个位置.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.21%)
 * Likes:    1552
 * Dislikes: 0
 * Total Accepted:    476.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 进阶：
 * 
 * 
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 * 
 * 
 */
/*左闭右开区间
 vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
    
        int l = 0, r = nums.size(); //二分范围
        while( l < r)			        //查找元素的开始位置
        {
            int mid = l+ (r - l)/2;
            if(nums[mid] == target)
                r = mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid;
        }
        //由于 while 的退出条件是 left == right ，取值范围是[0, nums.size()]所以当 target 比 nums 中所有元素都大时，会存在以下情况使得索引越界
        //查找失败
        if( l == nums.size() || nums[l] != target)
            return {-1, -1};

        int L = l;      
        l = 0, r = nums.size();     //二分范围
        while( l < r)                   //查找元素的结束位置
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target)
                l = mid + 1;                 
            else if(nums[mid] > target)
                r = mid;
            else if(nums[mid] == target)
                l = mid + 1;
        }
        if(r == 0 || nums[r-1] != target)
            return {-1, -1};
        int R = r - 1;
        return {L, R};
    }
*/
/* 左闭右闭区间
vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
    
        int l = 0, r = nums.size() - 1; //二分范围
        while( l <= r)			        //查找元素的开始位置
        {
            int mid = l+ (r - l)/2;
            if(nums[mid] == target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
        }
        //由于 while 的退出条件是 left == right + 1，所以当 target 比 nums 中所有元素都大时，会存在以下情况使得索引越界
        //查找失败
        if( l >= nums.size() || nums[l] != target) return {-1,-1};       
        int L = l;      
        l = 0, r = nums.size() - 1;     //二分范围
        while( l <= r)                   //查找元素的结束位置
        {
            int mid = (l + r )/2;
            if(nums[mid] < target)
                l = mid + 1;  
                
            else if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] == target)
                l = mid + 1;
        }
        if(r < 0 || nums[r] != target)
            return {-1, -1};
        int R = r;
        return {L, R};
    }
*/


//当左边界要更新为l = mid时，我们就令 mid =(l + r + 1)/2，上取整，
//此时就不会因为rr取特殊值r = l + 1而陷入死循环了。

#include<iostream>
#include<vector>

using namespace std;
// @lc code=start

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1,-1};
    
        int l = 0, r = nums.size() - 1; //二分范围
        while( l <= r)			        //查找元素的开始位置
        {
            int mid = l+ (r - l)/2;
            if(nums[mid] == target)
                r = mid - 1;
            else if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
        }
        //由于 while 的退出条件是 left == right + 1，所以当 target 比 nums 中所有元素都大时，会存在以下情况使得索引越界
        //查找失败
        if( l >= nums.size() || nums[l] != target) return {-1,-1};       
        int L = l;      
        l = 0, r = nums.size() - 1;     //二分范围
        while( l <= r)                   //查找元素的结束位置
        {
            int mid = (l + r )/2;
            if(nums[mid] < target)
                l = mid + 1;  
                
            else if(nums[mid] > target)
                r = mid - 1;
            else if(nums[mid] == target)
                l = mid + 1;
        }
        if(r < 0 || nums[r] != target)
            return {-1, -1};
        int R = r;
        return {L, R};
    }
};
// @lc code=end

