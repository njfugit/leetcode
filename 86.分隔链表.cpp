/*
 * @Author: Jack
 * @Date: 2022-09-17 13:08:54
 * @LastEditTime: 2022-09-17 13:41:41
 * @LastEditors: your name
 * @Description: koro1FileHeader
 * @FilePath: /.leetcode/86.分隔链表.cpp
 * 可以输入预定的版权声明、个性签名、空行等
 */
/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (63.71%)
 * Likes:    621
 * Dislikes: 0
 * Total Accepted:    176.7K
 * Total Submissions: 277.3K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 *
 * 你应当 保留 两个分区中每个节点的初始相对位置。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,4,3,2,5,2], x = 3
 * 输出：[1,2,2,4,3,5]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [2,1], x = 2
 * 输出：[1,2]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 200] 内
 * -100
 * -200
 *
 *
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *dummyhead1 = new ListNode(-1);
        ListNode *dummyhead2 = new ListNode(-1);
        ListNode *p1 = dummyhead1;
        ListNode *p2 = dummyhead2;
        ListNode *p = head;
        while (p != nullptr)
        {
            if (p->val >= x)
            {
                p2->next = p;
                p2 = p2->next;
            }
            else
            {
                p1->next = p;
                p1 = p1->next;
            }

            ListNode *temp = p->next;
            p->next = nullptr;
            p = temp;
        }
        p1->next = dummyhead2->next;

        return dummyhead1->next;
    }
};
// @lc code=end
