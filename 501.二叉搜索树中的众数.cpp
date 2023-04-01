/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (54.00%)
 * Likes:    531
 * Dislikes: 0
 * Total Accepted:    124.4K
 * Total Submissions: 230.3K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
 *
 * 如果树中有不止一个众数，可以按 任意顺序 返回。
 *
 * 假定 BST 满足如下定义：
 *
 *
 * 结点左子树中所含节点的值 小于等于 当前节点的值
 * 结点右子树中所含节点的值 大于等于 当前节点的值
 * 左子树和右子树都是二叉搜索树
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：root = [1,null,2,2]
 * 输出：[2]
 *
 *
 * 示例 2：
 *
 *
 * 输入：root = [0]
 * 输出：[0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中节点的数目在范围 [1, 10^4] 内
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 *
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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
    /* TreeNode* pre = nullptr;
    vector<int> result;
    int maxcount = 0;
    int count = 0;

    void bstsearch(TreeNode* cur) {
        if (cur == nullptr) return;
        bstsearch(cur->left);

        //处理中间节点
        if (pre == nullptr) {
            count = 1;
        } else if (pre->val == cur->val) {
            count++;
        } else {
            count = 1;
        }
        pre = cur;

        if(count == maxcount){
            result.push_back(cur->val);
        }
        if(count>maxcount){
            maxcount = count;
            result.clear();
            result.push_back(cur->val);
        }

        bstsearch(cur->right);

        return;
    } */
    vector<int> findMode(TreeNode* root) {
        /*result.clear();
        bstsearch(root);
        return result; */
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre = nullptr;
        vector<int> result;
        int count = 0;
        int maxcount = 0;

        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;//左
            } else {
                cur = st.top();//中
                st.pop();

                if (pre == nullptr) {
                    count = 1;
                } else if (cur->val == pre->val) {
                    count++;
                } else {
                    count = 1;
                }

                if (count == maxcount) {
                    result.push_back(cur->val);
                }
                if(count > maxcount){
                    result.clear();
                    maxcount = count;
                    result.push_back(cur->val);
                }
                pre = cur;
                cur = cur->right;//右
            }
        }
        return result;
    }
};
// @lc code=end
