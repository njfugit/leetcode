/*
 * @Author: Jack
 * @Date: 2022-09-27 19:43:21
 * @LastEditTime: 2022-09-27 20:46:04
 * @LastEditors: your name
 * @FilePath: /.leetcode/589.n-叉树的前序遍历.cpp
 */
/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (76.35%)
 * Likes:    316
 * Dislikes: 0
 * Total Accepted:    165.3K
 * Total Submissions: 216.4K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。
 *
 * n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：root = [1,null,3,2,4,null,5,6]
 * 输出：[1,3,5,6,2,4]
 *
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * 输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 节点总数在范围 [0, 10^4]内
 * 0 <= Node.val <= 10^4
 * n 叉树的高度小于或等于 1000
 *
 *
 *
 *
 * 进阶：递归法很简单，你可以使用迭代法完成此题吗?
 *
 */

// @lc code=start
/*
// Definition for a Node.*/
#include <bits/stdc++.h>
using namespace std;
// class Node {
// public:
//     int val;
//     vector<Node *> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node *> _children) {
//         val = _val;
//         children = _children;
//     }
// };

class Solution {
public:
    /* void Traversal(const Node *cur, vector<int> &vec) {
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        for (auto &node : cur->children)
            Traversal(node, vec);
    } */
    vector<int> preorder(Node *root) {
        /* vector<int> result;
        Traversal(root, result);
        return result; */
        stack<Node *> st;
        vector<int> result;
        if (root != nullptr) st.push(root);
        while (!st.empty()) {
            Node *node = st.top();
            if (node != nullptr) {
                st.pop();
                for (auto a = node->children.rbegin(); a != node->children.rend(); a++) {
                    st.push(*a);
                }
                st.push(node);
                st.push(nullptr);

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
