#include <iostream>
#include <map>

class NotEmpty {

public:
	NotEmpty() {}
	NotEmpty(int a): m_value(a) {}

private:
	int m_value;

};

int main()
{
	std::map<int, NotEmpty> m;
	// 需要默认构造才可以
	m[1] = NotEmpty(10);

	return 0;
}
