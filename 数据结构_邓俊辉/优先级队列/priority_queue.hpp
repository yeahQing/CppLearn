
template <typename T> struct PQ
{
    // 纯虚函数抽象接口
    virtual void insert( T ) = 0;
    virtual T getMax() = 0;
    virtual T delMax() = 0;
};