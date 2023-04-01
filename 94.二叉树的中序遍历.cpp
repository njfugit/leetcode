/*
 * @Author: Jack
 * @Date: 2022-09-25 19:20:05
 * @LastEditTime: 2022-09-26 13:42:14
 * @LastEditors: your name
 * @FilePath: /.leetcode/94.二叉树的中序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Easy (76.12%)
 * Likes:    1574
 * Dislikes: 0
 * Total Accepted:    965.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,3]
 * 输出：[1,3,2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 *
 * 输入：root = [1]
 * 输出：[1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点数目在范围 [0, 100] 内
 * -100 <= Node.val <= 100
 *
 *
 *
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 *
 */

// @lc code=start
// Definition for a binary tree node.
#include <bits/stdc++.h>

using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    // void Traversal(TreeNode *cur, vector<int> &vec) {
    //     if (cur == nullptr) return;
    //     Traversal(cur->left, vec);
    //     vec.push_back(cur->val);
    //     Traversal(cur->right, vec);
    // }

    vector<int> inorderTraversal(TreeNode *root) {
        // vector<int> result;
        // Traversal(root, result);
        // return result;
        /* stack<TreeNode *> st;
        vector<int> result;
        TreeNode *node = root;
        while (node != nullptr || !st.empty()) {
            //先遍历左子树
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();  //取出最后一个左子叶
                st.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result; */
        stack<TreeNode *> st;
        vector<int> result;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != nullptr) {
                st.pop();
                if (node->right) st.push(node->right);
                st.push(node);
                st.push(nullptr);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }
};
// @lc code=end
