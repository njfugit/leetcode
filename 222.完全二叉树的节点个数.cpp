/*
 * @Author: Jack
 * @Date: 2022-09-30 19:47:56
 * @LastEditTime: 2022-09-30 20:55:27
 * @LastEditors: your name
 * @FilePath: /.leetcode/222.完全二叉树的节点个数.cpp
 */
/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 *
 * https://leetcode.cn/problems/count-complete-tree-nodes/description/
 *
 * algorithms
 * Medium (80.36%)
 * Likes:    789
 * Dislikes: 0
 * Total Accepted:    225.5K
 * Total Submissions: 280.6K
 * Testcase Example:  '[1,2,3,4,5,6]'
 *
 * 给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
 *
 * 完全二叉树
 * 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h
 * 层，则该层包含 1~ 2^h 个节点。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,4,5,6]
 * 输出：6
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：0
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是[0, 5 * 10^4]
 * 0
 * 题目数据保证输入的树是 完全二叉树
 *
 *
 *
 *
 * 进阶：遍历树来统计节点是一种时间复杂度为 O(n) 的简单解决方案。你可以设计一个更快的算法吗？
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
    /* int getnums(TreeNode *node) {
        if (node == nullptr) return 0;
        //后序遍历
        int leftnums = getnums(node->left);    //左
        int rightnums = getnums(node->right);  //右
        return leftnums + rightnums + 1;
    } */
    int countNodes(TreeNode *root) {
        /*  return getnums(root); */
        // queue<TreeNode *> que;
        // int nums = 0;
        // if (root == nullptr) return 0;
        // que.push(root);
        // while (!que.empty()) {
        //     int size = que.size();
        //     for (int i = 0; i < size; i++) {
        //         TreeNode *node = que.front();
        //         que.pop();
        //         nums++;
        //         if (node->left) que.push(node->left);
        //         if (node->right) que.push(node->right);

        //     }
        // }
        // return nums;

        //判断其子树岂不是满二叉树，如果是则利用用公式计算这个子树（满二叉树）的节点数量，如果不是则继续递归
        if (root == nullptr) return 0;
        TreeNode *leftnode = root->left;
        TreeNode *rightnode = root->right;
        int leftdepth = 0, rightdepth = 0;
        while (leftnode) {
            leftnode = leftnode->left;
            leftdepth++;
        }
        while (rightnode) {
            rightnode = rightnode->right;
            rightdepth++;
        }

        if (leftdepth == rightdepth) {
            return (2 << leftdepth) - 1;
        }

        int leftnums = countNodes(root->left);
        int rightnums = countNodes(root->right);
        int nums = leftnums + rightnums + 1;
        return nums;
    }
};
// @lc code=end
