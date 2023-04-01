/*
 * @Author: Jack
 * @Date: 2022-09-28 16:30:34
 * @LastEditTime: 2022-09-28 19:52:47
 * @LastEditors: your name
 * @FilePath: /.leetcode/101.对称二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (58.25%)
 * Likes:    2123
 * Dislikes: 0
 * Total Accepted:    696.9K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,2,3,4,4,3]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,null,3,null,3]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [1, 1000] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
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
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /* bool compare(TreeNode *left, TreeNode *right) {
        //判断有节点为空的情况
        if (left == nullptr && right != nullptr) {
            return false;
        } else if (left != nullptr && right == nullptr) {
            return false;
        } else if (left == nullptr && right == nullptr) {
            return true;
        } else if (left->val != right->val) {
            return false;
        }

        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);

        return (outside && inside);
    } */
    bool isSymmetric(TreeNode *root) {
        /* if (root == nullptr) return true;

        return compare(root->left, root->right); */

        if (root == nullptr) return true;
        stack<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            TreeNode *leftnode = que.top();
            que.pop();
            TreeNode *rightnode = que.top();
            que.pop();
            if (!leftnode && !rightnode) {  //两个都为空
                continue;
            }
            if (!leftnode || !rightnode || (leftnode->val != rightnode->val)) {
                return false;
            }
            que.push(leftnode->left);
            que.push(rightnode->right);
            que.push(leftnode->right);
            que.push(rightnode->left);
        }
        return true;
    }
};
// @lc code=end
