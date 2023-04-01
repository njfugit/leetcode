/*
 * @Author: Jack
 * @Date: 2022-09-28 19:59:25
 * @LastEditTime: 2022-10-04 14:46:54
 * @LastEditors: your name
 * @FilePath: /.leetcode/572.另一棵树的子树.cpp
 */
/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 *
 * https://leetcode-cn.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (47.66%)
 * Likes:    828
 * Dislikes: 0
 * Total Accepted:    146.4K
 * Total Submissions: 307.5K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 *
 *
 * 给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true
 * ；否则，返回 false 。
 *
 * 二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [3,4,5,1,2], subRoot = [4,1,2]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * root 树上的节点数量范围是 [1, 2000]
 * subRoot 树上的节点数量范围是 [1, 1000]
 * -10^4
 * -10^4
 *
 *
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
//     TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    bool compare(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q != nullptr)
            return false;
        else if (p != nullptr && q == nullptr)
            return false;
        else if (p == nullptr && q == nullptr)
            return true;
        else if (p->val != q->val)
            return false;

        bool outside = compare(p->left, q->left);
        bool inside = compare(p->right, q->right);

        return (inside && outside);
    }
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if (p == nullptr && q == nullptr) return true;
    //     if (p == nullptr || q == nullptr) return false;
    //     queue<TreeNode*> que;
    //     que.push(p);
    //     que.push(q);
    //     while (!que.empty()) {
    //         TreeNode* leftNode = que.front();
    //         que.pop();
    //         TreeNode* rightNode = que.front();
    //         que.pop();
    //         if (!leftNode && !rightNode) {
    //             continue;
    //         }
    //         if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
    //             return false;
    //         }
    //         // 相对于求对称二叉树，这里两个树都要保持一样的遍历顺序
    //         que.push(leftNode->left);
    //         que.push(rightNode->left);
    //         que.push(leftNode->right);
    //         que.push(rightNode->right);
    //     }
    //     return true;
    // }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false;
        bool res1 = compare(root, subRoot);
        bool res2 = isSubtree(root->left, subRoot);
        bool res3 = isSubtree(root->right, subRoot);
        return res1 || res2 || res3;
        // if (root == nullptr) return false;
        // bool res1 = isSameTree(root, subRoot);
        // bool res2 = isSubtree(root->left, subRoot);
        // bool res3 = isSubtree(root->right, subRoot);
        // return res1 || res2 || res3;
    }
};
// @lc code=end
