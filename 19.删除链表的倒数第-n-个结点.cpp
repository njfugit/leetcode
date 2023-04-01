/*
 * @Author: Jack
 * @Date: 2022-04-04 23:50:57
 * @LastEditTime: 2022-04-05 00:11:17
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/19.删除链表的倒数第-n-个结点.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (43.74%)
 * Likes:    1937
 * Dislikes: 0
 * Total Accepted:    728.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5], n = 2
 * 输出：[1,2,3,5]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1], n = 1
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1,2], n = 1
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中结点的数目为 sz
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
 * 
 * 
 * 
 * 
 * 进阶：你能尝试使用一趟扫描实现吗？
 * 
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
/* struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 */
//关于指针类型题目注意虚拟节点的使用
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //当快指针先走n步，然后慢指针与快指针一起走，慢指针所在位置就是
        ListNode *new_head = new ListNode();
        new_head->next = head;
        ListNode* p = new_head;
        ListNode* q = new_head;
        for (int i = 0; i < n + 1; i++){//为了找到倒数第k+1个数，方便删除
            p = p->next;
        }
        while (p != nullptr){
            p = p->next;
            q = q->next;
        }
        q->next = q->next->next;

        return new_head->next;
    }
};
// @lc code=end

