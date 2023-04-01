/*
 * @Author: Jack
 * @Date: 2022-03-31 23:18:45
 * @LastEditTime: 2022-09-17 14:28:46
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/23.合并k个升序链表.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (56.68%)
 * Likes:    1861
 * Dislikes: 0
 * Total Accepted:    430.9K
 * Total Submissions: 759.5K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 *
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 *
 *
 */

/*
法一、新定义一个结构体，操作符重载
struct NewNode{
        int val;
        ListNode *ptr;
        NewNode(int _val, ListNode *p):val(_val), ptr(p){}
        bool operator < (const NewNode &temp) const
        {
            return temp.val < val;
        }
    };
    priority_queue<NewNode> pq;
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if(lists.empty())
            return nullptr;
        for (auto node : lists)
        {
            if(node)
                pq.push({node->val, node});
        }
        ListNode *head = new ListNode();
        ListNode *p = head;
        while (!pq.empty())
        {
            NewNode q = pq.top();
            pq.pop();
            p->next = q.ptr;

            if (q.ptr->next != nullptr)
            {
                pq.push({q.ptr->next->val, q.ptr->next});
            }
            p = p->next;
        }
        return head->next;
    }
*/

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
class Solution
{
public:
    struct NewNode
    { //重载仿函数，由小到大排序

        bool operator()(ListNode *t1, ListNode *t2)
        {
            return t1->val >= t2->val;
        }
    };
    priority_queue<ListNode *, vector<ListNode *>, NewNode> pq;
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        for (auto node : lists)
        {
            if (node)
                pq.push(node);
        }
        ListNode *head = new ListNode();
        ListNode *p = head;
        while (!pq.empty())
        {
            ListNode *q = pq.top();
            pq.pop();
            p->next = q;

            if (q->next != nullptr)
            {
                pq.push(q->next);
            }
            p = p->next;
        }
        return head->next;
    }
};
// @lc code=end
