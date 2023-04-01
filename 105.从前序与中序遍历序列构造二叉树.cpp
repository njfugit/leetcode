/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (71.38%)
 * Likes:    1755
 * Dislikes: 0
 * Total Accepted:    426.4K
 * Total Submissions: 597.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder
 * 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
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
/* struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
}; */
class Solution {
public:
    TreeNode* traversal(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int istart, int iend) {
        if ((preend - prestart) == 0 || (iend - istart) == 0) return nullptr;
        int rootval = preorder[prestart];
        TreeNode* root = new TreeNode(rootval);
        if ((preend - prestart) == 1) return root;

        int inordersplit;
        for (inordersplit = istart; inordersplit < iend; inordersplit++) {
            if (inorder[inordersplit] == rootval) break;
        }

        int leftinorderstart = istart;
        int leftinorderend = inordersplit;
        int rightinorderstart = inordersplit + 1;
        int rightinorderend = iend;

        int leftpreorderstart = prestart + 1;
        int leftpreorderend = prestart + 1 + inordersplit - istart;
        int rightpreorderstart = prestart + 1 + inordersplit - istart;
        int rightpreorderend = preend;

        root->left = traversal(preorder, leftpreorderstart, leftpreorderend, inorder, leftinorderstart, leftinorderend);
        root->right = traversal(preorder, rightpreorderstart, rightpreorderend, inorder, rightinorderstart, rightinorderend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
// @lc code=end
