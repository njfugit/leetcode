/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (77.18%)
 * Likes:    1170
 * Dislikes: 0
 * Total Accepted:    307.7K
 * Total Submissions: 398.6K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
 *
 * 高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [-10,-3,0,5,9]
 * 输出：[0,-3,9,-10,null,5]
 * 解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
 *
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [1,3]
 * 输出：[3,1]
 * 解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * nums 按 严格递增 顺序排列
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    // TreeNode* traversal(vector<int>& nums, int left, int right){
    //     if (left > right) return nullptr;
    //     int mid = left + ((right - left) / 2);
    //     TreeNode* root = new TreeNode(nums[mid]);
    //     root->left = traversal(nums, left, mid - 1);
    //     root->right = traversal(nums, mid + 1, right);
    //     return root;
    // }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // TreeNode* root = traversal(nums, 0, nums.size() - 1);
        // return root;
        //迭代法 一个队列放遍历的节点，一个队列放左区间下标，一个队列放右区间下标
        //分割思路，将数组分为左右的两部分
        if (nums.size() == 0) return nullptr;
        queue<TreeNode*> que;
        queue<int> rightnode;
        queue<int> leftnode;

        TreeNode* root = new TreeNode(0);
        que.push(root);
        leftnode.push(0);                 //左下标初始值
        rightnode.push(nums.size() - 1);  //右下标初始值

        while (!que.empty()) {
            TreeNode* cur = que.front(); 
            que.pop();

            int left = leftnode.front();
            leftnode.pop();
            int right = rightnode.front();
            rightnode.pop();

            int mid = left + ((right - left) / 2);  //处理中间节点
            cur->val = nums[mid];

            if (left <= mid - 1) {  //处理左节点
                cur->left = new TreeNode(0);
                que.push(cur->left);
                leftnode.push(left);
                rightnode.push(mid - 1);
            }

            if (right >= mid + 1) {  //处理右节点
                cur->right = new TreeNode(0);
                que.push(cur->right);
                leftnode.push(mid + 1);
                rightnode.push(right);
            }
        }
        return root;
    }
};
// @lc code=end
