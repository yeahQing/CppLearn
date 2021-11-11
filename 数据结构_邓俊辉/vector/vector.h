#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef int Rank;

#define DEFAULT_CAPACITY 3

template <typename T>
class Vector {
protected:
    Rank _size; // 动态数组(向量)的规模
    int _capacity;  // 动态数组(向量)的容量
    T* _elem;   // 动态数组(向量)的数据区
	// TODO
    void copyFrom(T const* A, Rank lo, Rank hi);
public:
    // TODO
    // 构造函数
    
};


#endif // __VECTOR_H__