/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (72.54%)
 * Likes:    853
 * Dislikes: 0
 * Total Accepted:    235K
 * Total Submissions: 324K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder
 * 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
 * 输出：[3,9,20,null,null,15,7]
 *
 *
 * 示例 2:
 *
 *
 * 输入：inorder = [-1], postorder = [-1]
 * 输出：[-1]
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= inorder.length <= 3000
 * postorder.length == inorder.length
 * -3000 <= inorder[i], postorder[i] <= 3000
 * inorder 和 postorder 都由 不同 的值组成
 * postorder 中每一个值都在 inorder 中
 * inorder 保证是树的中序遍历
 * postorder 保证是树的后序遍历
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
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    TreeNode* Traversal(vector<int>& inorder, int istart, int iend, vector<int>& postorder, int pstart, int pend) {
        if (istart == iend || pstart == pend) return nullptr;
        int rootval = postorder[pend - 1];  //取出根节点
        TreeNode* root = new TreeNode(rootval);
        if ((pend - pstart) == 1) return root;

        int inordersplit;  //找出中序排列中的根节点索引
        for (inordersplit = istart; inordersplit < iend; inordersplit++) {
            if (inorder[inordersplit] == rootval)
                break;
        }
        //区间是左闭右开
        /* vector<int> inorderleft(inorder.begin(), inorder.begin() + inordersplit);
        vector<int> inorderright(inorder.begin() + inordersplit + 1, inorder.end());

        vector<int> postorderleft(postorder.begin(), postorder.begin() + inorderleft.size());
        vector<int> postorderright(postorder.begin() + inorderleft.size(), postorder.end() - 1);

        root->left = Traversal(inorderleft, postorderleft);
        root->right = Traversal(inorderright, postorderright); */

        int leftinorderstart = istart;
        int leftinorderend = inordersplit;
        int rightinorderstart = inordersplit + 1;
        int rightinorderend = iend;

        int leftpostorderstart = pstart;
        int leftpostorderend = pstart + inordersplit - istart;
        int rightpostorderstart = pstart + inordersplit - istart;
        int rightpostorderend = pend - 1;

        root->left = Traversal(inorder, leftinorderstart, leftinorderend, postorder, leftpostorderstart, leftpostorderend);
        root->right = Traversal(inorder, rightinorderstart, rightinorderend, postorder, rightpostorderstart, rightpostorderend);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return Traversal(inorder,0,inorder.size(), postorder,0,postorder.size());
    }
};
// @lc code=end
