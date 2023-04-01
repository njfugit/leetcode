/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode.cn/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (61.56%)
 * Likes:    510
 * Dislikes: 0
 * Total Accepted:    187K
 * Total Submissions: 303.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定二叉树的根节点 root ，返回所有左叶子之和。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入: root = [3,9,20,null,null,15,7]
 * 输出: 24
 * 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 *
 *
 * 示例 2:
 *
 *
 * 输入: root = [1]
 * 输出: 0
 *
 *
 *
 *
 * 提示:
 *
 *
 * 节点数在 [1, 1000] 范围内
 * -1000 <= Node.val <= 1000
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
    int sumOfLeftLeaves(TreeNode* root) {
        /* if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 0;
        int leftval = sumOfLeftLeaves(root->left);
        if (root->left && root->left->left == nullptr && root->left->right == nullptr) {
            leftval = root->left->val;

        }
        int rightval = sumOfLeftLeaves(root->right);
        int sum = leftval + rightval;
        return sum; */
        stack<TreeNode*> st;
        int result=0;
        if (root == nullptr) return 0;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->left && node->left->left == nullptr && node->left->right == nullptr){
                result += node->left->val;
            }
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        return result;
    }
};
// @lc code=end
