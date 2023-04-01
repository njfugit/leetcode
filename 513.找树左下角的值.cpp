/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode.cn/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (74.34%)
 * Likes:    391
 * Dislikes: 0
 * Total Accepted:    144.7K
 * Total Submissions: 194.6K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
 *
 * 假设二叉树中至少有一个节点。
 *
 *
 *
 * 示例 1:
 *
 *
 *
 *
 * 输入: root = [2,1,3]
 * 输出: 1
 *
 *
 * 示例 2:
 *
 * ⁠
 *
 *
 * 输入: [1,2,3,4,null,5,6,null,null,7]
 * 输出: 7
 *
 *
 *
 *
 * 提示:
 *
 *
 * 二叉树的节点个数的范围是 [1,10^4]
 * -2^31  
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
#include <limits.h>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode() : val(0), left(nullptr), right(nullptr){} * TreeNode(int x) : val(x), left(nullptr), right(nullptr){} * TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
// };
class Solution {
public:
    //记录最大深度
    /* int result;
    int maxdepth = INT_MIN;
    void traversal(TreeNode* node, int depth) {
        if (node == nullptr) result = 0;
        if (node->left == nullptr && node->right == nullptr) {
            if(depth>maxdepth){
                maxdepth = depth;
                result = node->val;
            }
            return;
        }
        if(node->left) {
            traversal(node->left, depth+1);
        }
        if(node->right) {
            traversal(node->right, depth+1);
        }
        return;
    } */

    int findBottomLeftValue(TreeNode* root) {
        /* traversal(root, 0);
        return result; */
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = que.front();
                que.pop();
                if (i == 0) result = node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return result;
    }
};
// @lc code=end
