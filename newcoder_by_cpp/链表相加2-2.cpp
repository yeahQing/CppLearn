/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>

using namespace std;

struct ListNode
{
    /* data */
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /**
     *
     * @param head1 ListNode类
     * @param head2 ListNode类
     * @return ListNode类
     */
    ListNode *addInList(ListNode *head1, ListNode *head2)
    {

        if (head1 == NULL && head2 == NULL)
        {
            return NULL;
        }
        else if (head1 == NULL || head2 == NULL)
        {
            return head1 == NULL ? head2 : head1;
        }

        // 反转head1
        head1 = reverse(head1);
        // 反转head2
        head2 = reverse(head2);

        // 创建新的链表头节点
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;

        int carry = 0;

        while (head1 != NULL || head2 != NULL)
        {
            int num = carry;

            if (head1 != NULL)
            {
                num += head1->val;
                head1 = head1->next;
            }

            if (head2 != NULL)
            {
                num += head2->val;
                head2 = head2->next;
            }

            // 求出进位
            carry = num / 10;
            num = num % 10;

            cur->next = new ListNode(num);
            cur = cur->next;
        }

        if (carry > 0)
            cur->next = new ListNode(carry);

        return reverse(head->next);
    }

    ListNode *reverse(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *cur = head;
        ListNode *pre = NULL;

        while (cur != NULL)
        {
            ListNode *tail = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tail;
        }

        return pre;
    }
};