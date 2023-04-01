/*
 * @Author: Jack
 * @Date: 2022-09-30 12:05:00
 * @LastEditTime: 2022-09-30 19:07:21
 * @LastEditors: your name
 * @FilePath: /.leetcode/111.二叉树的最小深度.cpp
 */
/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (51.09%)
 * Likes:    849
 * Dislikes: 0
 * Total Accepted:    462.5K
 * Total Submissions: 905.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 *
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 *
 * 说明：叶子节点是指没有子节点的节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：2
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [2,null,3,null,4,null,5,null,6]
 * 输出：5
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数的范围在 [0, 10^5] 内
 * -1000
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
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    /* int getdepth(TreeNode *node) {
        if (node == nullptr) return 0;
        int leftdepth = getdepth(node->left);
        int rightdepth = getdepth(node->right);
        //后序遍历
        if (node->left != nullptr && node->right == nullptr) return 1 + leftdepth;
        if (node->left == nullptr && node->right != nullptr) return 1 + rightdepth;
        int result = 1 + min(leftdepth, rightdepth);
        return result;
    } */
    int minDepth(TreeNode *root) {
        /* return getdepth(root); */
        queue<TreeNode *> que;
        if (root == nullptr) return 0;
        que.push(root);
        int depth = 0;
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (!node->left &&!node->right){
                    return depth;
                }
            }
        }
        return depth;
    }
};
// @lc code=end
