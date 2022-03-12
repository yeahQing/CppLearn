#include <iostream>

using namespace std;

template <typename T>
struct Node {
	T val;
	Node* next;
	Node() {}
	Node(T v): val(v), next(NULL) {}
	virtual void echoNode() const {
		cout << val << endl;
	}
};

template <typename T>
struct ListNode : Node<T> {
	int val;
	ListNode* next;
	Node<T>* node;
	ListNode(int v): val(v), node(new Node<T>(v)), next(NULL) {}
	virtual void echoNode() const override {
		cout << val << endl;
	}
	~ListNode() {
		delete node;
	}
};

int main()
{
	Node<int> node(1);
	node.echoNode();

	// 多态性
	Node<int>* head = new ListNode<int>(5);
	head->echoNode();

	return 0;
}

