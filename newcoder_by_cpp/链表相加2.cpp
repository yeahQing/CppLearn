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
    ListNode(int x): val(x), next(NULL) {}
};


class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* addInList(ListNode* head1, ListNode* head2) {

        if (head1 == NULL) return head2;
        if (head2 == NULL) return head1;
        
        // write code here
        ListNode* cur = head1, *pre = NULL;
        ListNode* p = NULL, *q = NULL;
        int n = 0, m = 0;
        while (cur != NULL) {
            p = new ListNode(cur->val);
            p->next = pre;
            pre = p;
            cur = cur->next;
            n++;
        }
        
        pre = NULL;
        cur = head2;
        while (cur != NULL)
        {
            q = new ListNode(cur->val);
            q->next = pre;
            pre = q;
            cur = cur->next;
            m++;
        }
        pre = NULL;

        int next_traverse = m == n ? 0 : max(m, n);
        int carry = 0;
        int num = 0;
        ListNode* newNode = NULL;
        ListNode* head = NULL;
        
        
        while (p != NULL && q != NULL)
        {
            num = p->val+q->val+carry;
            carry = num / 10; 
            num %= 10;
            newNode = new ListNode(num);
            newNode->next = head;
            head = newNode;
            p = p->next; 
            q = q->next;
        }
        
        
        if (next_traverse == n)
        {
            while (p != NULL)
            {
                num = p->val + carry;
                carry = num / 10; 
                num %= 10;
                newNode = new ListNode(num);
                newNode->next = head;
                head = newNode;
                p = p->next;
            }
        }else
        {
            while (q != NULL)
            {
                num = q->val + carry;
                carry = num / 10; 
                num %= 10;
                newNode = new ListNode(num);
                newNode->next = head;
                head = newNode;
                q = q->next;
            }
        }
        
        if (carry == 1)
        {
            newNode = new ListNode(carry);
            newNode->next = head;
            head = newNode;
        }
        
        delete p, q, newNode;
        return head;
    }
};