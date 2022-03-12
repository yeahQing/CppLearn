/**
 * BM3 链表中的节点每k个一组翻转
 */

#include <iostream>
#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(nullptr) {}
    ~ListNode() { delete next; }
};

ListNode *createList(int n)
{
    ListNode *head = new ListNode();
    ListNode *cur = head;
    while (n--)
    {
        ListNode *node = new ListNode();
        std::cin >> node->val;
        cur->next = node;
        cur = node;
        // delete node;
    }
    cur = head->next;
    // delete head;
    return cur;
}

void printList(ListNode *head)
{
    ListNode *cur = head;
    std::cout << cur->val;
    cur = cur->next;
    while (cur != nullptr)
    {
        std::cout << "->" << cur->val;
        cur = cur->next;
    }
    std::cout << std::endl;
}

ListNode *reverse(ListNode *head, ListNode *tail)
{
    ListNode *cur = head;
    ListNode *pre = nullptr;

    while (cur != tail)
    {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    // write code here
    int cnt = 0;
    ListNode *tail = head;
    ListNode *cur = head;
    std::stack<ListNode *> s_head;
    std::stack<ListNode *> s_tail;
    while (true)
    {
        if (cnt < k)
        {
            // 不够k个
            if (tail == nullptr)
            {
                while (!s_head.empty() && !s_tail.empty())
                {
                    ListNode *newtail = s_tail.top();
                    s_tail.pop();
                    newtail->next = cur;
                    cur = s_head.top();
                    s_head.pop();
                }
                break;
            }
            tail = tail->next;
            cnt++;
        }
        else
        {
            cnt = 0;
            // 反转
            ListNode *newhead = reverse(cur, tail);
            s_head.push(newhead);
            s_tail.push(cur);
            cur = tail;
        }
    }
    return cur;
}

int main()
{
    int n, k;
    std::cin >> n >> k;
    ListNode *head = createList(n);
    printList(head);
    head =reverseKGroup(head, k);
    printList(head);
    return 0;
}