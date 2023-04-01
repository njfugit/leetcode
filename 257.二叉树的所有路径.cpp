/*
 *                                                     __----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          __--~ ~~
 *                    -.            \_|//     |||\\  ~~~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \\            _/~~-
 *         __---~~~.==~||\=_    -_--~/_-~|-   |\\   \\        _/~
 *     _-~~     .=~    |  \\-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \\ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \\ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       __--~~
 *                       |-~~-_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-~~____--~-/                  ~~==.
 *                       ((->/~   '.|||' -_|    ~~-/ ,              . _||
 *                                  -_     ~\      ~~---l__i__i__i--~~_/
 *                                  _-~-__   ~)  \--______________--~~
 *                                //.-~~~-~_--~- |-------~~~~~~~~
 *                                       //.-~~~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                               神兽保佑            永无BUG
 *
 * @Author: Jack
 * @Date: 2022-10-02 16:33:27
 * @LastEditTime: 2022-10-04 12:38:22
 * @LastEditors: your name
 * @FilePath: /.leetcode/257.二叉树的所有路径.cpp
 */

/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (70.27%)
 * Likes:    816
 * Dislikes: 0
 * Total Accepted:    250K
 * Total Submissions: 355.5K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
 *
 * 叶子节点 是指没有子节点的节点。
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,2,3,null,5]
 * 输出：["1->2->5","1->3"]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1]
 * 输出：["1"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 100] 内
 * -100 <= Node.val <= 100
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
    /* void traversal(TreeNode *node, vector<int> &path, vector<string> &result) {
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            //把path里面保存的值连成一条路径，结果保存
            string ss;
            for (int i = 0; i < path.size() - 1; i++) {
                ss += to_string(path[i]);
                ss += "->";
            }
            ss += to_string(path[path.size() - 1]);
            result.push_back(ss);
            return;
        }

        if (node->left) {
            traversal(node->left, path, result);
            path.pop_back();
        }
        if (node->right) {
            traversal(node->right, path, result);
            path.pop_back();
        }
    } */
    vector<string> binaryTreePaths(TreeNode *root) {
        /* vector<string> result;
        vector<int> path;
        if (root == nullptr) return result;
        traversal(root, path, result);
        return result; */

        stack<TreeNode *> st;  //遍历节点
        stack<string> ss;      //保存遍历的路径节点
        vector<string> result;
        if (root == nullptr) return result;
        st.push(root);
        ss.push(to_string(root->val));
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            string path = ss.top();
            ss.pop();
            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(path);
            }

            if (node->right) {
                st.push(node->right);
                ss.push(path + "->" + to_string(node->right->val));
            }
            if (node->left) {
                st.push(node->left);
                ss.push(path + "->" + to_string(node->left->val));
            }
        }
        return result;
    }
};

// @lc code=end

