/*
 * @Author: Jack
 * @Date: 2022-09-28 21:18:51
 * @LastEditTime: 2022-09-29 22:33:29
 * @LastEditors: your name
 * @FilePath: /.leetcode/104.二叉树的最大深度.cpp
 */
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (77.11%)
 * Likes:    1386
 * Dislikes: 0
 * Total Accepted:    854.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 *
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * 返回它的最大深度 3 。
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
        int depth = max(leftdepth, rightdepth) + 1;
        return depth;
    } */
    // int result;
    // void getdepth(TreeNode *node, int depth) {
    //     result = depth > result ? depth : result;

    //     if (node->left == nullptr && node->right == nullptr) return;

    //     if (node->left) {
    //         depth++;
    //         getdepth(node->left, depth);
    //         depth--;
    //     }

    //     if (node->right) {
    //         depth++;
    //         getdepth(node->right, depth);
    //         depth--;
    //     }

    //     return;
    // }
    int maxDepth(TreeNode *root) {
        // result = 0;
        // if (root == nullptr) return result;
        // getdepth(root, 1);
        // return result;
        queue<TreeNode *> que;
        if (root == nullptr) return 0;
        int depth = 0;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
};
// @lc code=end
