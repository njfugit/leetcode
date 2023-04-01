/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (63.38%)
 * Likes:    383
 * Dislikes: 0
 * Total Accepted:    140.7K
 * Total Submissions: 221.8K
 * Testcase Example:  '[4,2,6,1,3]'
 *
 * 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
 *
 * 差值是一个正数，其数值等于两值之差的绝对值。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [4,2,6,1,3]
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [1,0,48,null,null,12,49]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目范围是 [2, 10^4]
 * 0 <= Node.val <= 10^5
 *
 *
 *
 *
 * 注意：本题与 783
 * https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同
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
    // TreeNode* pre = nullptr;
    // void traversal(TreeNode* cur, int& result) {
    //     /* if (root == nullptr) return;
    //     traversal(root->left, result);
    //     result.push_back(root->val);
    //     traversal(root->right, result); */
    //     if (cur == nullptr) return;
    //     traversal(cur->left, result);
    //     if (pre != nullptr) result = min(result, cur->val - pre->val);
    //     pre = cur;
    //     traversal(cur->right, result);
    // }
    int getMinimumDifference(TreeNode* root) {
        /* vector<int> result;
        traversal(root, result);
        if (result.size() < 2) return 0;
        int minval = INT_MAX;
        for (int i = 1; i < result.size();i++){
            minval = min(minval, result[i] - result[i - 1]);
        }
        return minval; */
        // int result = INT_MAX;
        // traversal(root, result);
        // return result;

        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        int result = INT_MAX;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                if (pre != nullptr) {
                    result = min(result, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return result;
    }
};
// @lc code=end
