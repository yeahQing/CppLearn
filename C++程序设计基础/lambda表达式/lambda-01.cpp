#include <iostream>
#include <memory>

struct ListNode {

    int val;
    ListNode* next;

    ListNode(int v): val(v), next(nullptr) {}

    ListNode(ListNode&& node)
    {
        val = node.val;
        next = node.next;
        node.next = nullptr;
    }
    ~ListNode() { 
        std::cout << "id: {" << val  << "} is destructor..." << std::endl; 
        std::cout << next << std::endl;
    }

    void myPrint() {
        std::cout << val << std::endl;
    }

};

int main()
{

    int x = 1;

    // 表达式必须是可修改的左值， 左值是保存在内存中的值，右值是
    auto f = [x = 0] () mutable { return x++; };
    auto f3 = [x = x]() mutable -> void {std::cout << ++x << std::endl;};
    std::cout << f() << std::endl;

    f3();

    auto f1 = [&x = x] {return x++;};
    std::cout << f1() << std::endl;

    auto p = std::make_unique<int>(1);    

    std::cout << "p.get()=" << p.get() << " " << *p << std::endl;

    // auto f2 = [&p = std::move(p)] {*p = 100;};
    auto f2 = [&p = p] {*p += 100; std::cout << "p.get()=" << p.get() << " " << *p << std::endl;};

    // auto p1 = f2();
    f2();

    std::cout << "p.get()=" << p.get() << " " << *p << std::endl;
    // std::cout << "p1.get()=" << p1.get() << std::endl;

    // std::unique_ptr<ListNode> up = std::make_unique<ListNode>(1);
    // auto up = std::make_unique<ListNode>(new ListNode(1));
    // ListNode* cur = up.get();
    std::unique_ptr<ListNode> up(new ListNode(1));
    std::unique_ptr<ListNode> taskPtr(new std::unique_ptr<ListNode>::element_type(5));
    // cur->myPrint();
    up->myPrint();
    up.release();
    up.reset(new ListNode(23));
    up->myPrint();
    taskPtr->myPrint();
    
    std::unique_ptr<ListNode> ptr1 = std::make_unique<ListNode>(15);
    // ptr1->next = std::make_unique<ListNode>(new ListNode(1));

    ListNode* cur= ptr1.get();
    cur->next = new ListNode(10);

    ListNode* node(cur);
    std::cout << "node:";
    node->val = 30;
    node->myPrint();

    while (cur != nullptr)
    {
        cur->myPrint();
        cur = cur->next;
    }

    return 0;
}