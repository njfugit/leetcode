/*
 * @Author: Jack
 * @Date: 2022-10-02 15:16:47
 * @LastEditTime: 2022-10-03 12:44:45
 * @LastEditors: your name
 * @FilePath: /.leetcode/110.平衡二叉树.cpp
 */
/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode.cn/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (57.32%)
 * Likes:    1145
 * Dislikes: 0
 * Total Accepted:    423.3K
 * Total Submissions: 738.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 *
 * 本题中，一棵高度平衡二叉树定义为：
 *
 *
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,9,20,null,null,15,7]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,2,2,3,3,null,null,4,4]
 * 输出：false
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = []
 * 输出：true
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中的节点数在范围 [0, 5000] 内
 * -10^4
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    /* int getheight(TreeNode *node) {
        if (node == nullptr) return 0;
        int leftheight = getheight(node->left);
        if (leftheight == -1) return -1;
        int rightheight = getheight(node->right);
        if (rightheight == -1) return -1;

        if (abs(leftheight - rightheight) > 1) {
            return -1;
        } else {
            return 1 + max(leftheight, rightheight);
        }
    } */
    //通过求传入节点为根节点的最大深度
    int getdepth(TreeNode *node) {
        stack<TreeNode *> st;
        int depth = 0;
        int result = 0;
        if (node != nullptr) st.push(node);
        while (!st.empty()) {
            TreeNode *tn = st.top();
            if (tn != nullptr) {
                st.pop();
                st.push(tn);
                st.push(nullptr);
                depth++;
                if (tn->right) st.push(tn->right);
                if (tn->left) st.push(tn->left);
            } else {
                st.pop();
                tn = st.top();
                st.pop();
                depth--;
            }
            result = result > depth ? result : depth;
        }
        return result;
    }
    bool isBalanced(TreeNode *root) {
        /* if (getheight(root) != -1)
            return true;
        else
            return false; */

        //用栈来模拟后序遍历
        //求深度适合用前序遍历，而求高度适合用后序遍历。
        stack<TreeNode *> st;
        if (root == nullptr) return true;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            if (abs(getdepth(node->left) - gedetdepth(node->right)) > 1) return false;
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return true;
    }
};
// @lc code=end
