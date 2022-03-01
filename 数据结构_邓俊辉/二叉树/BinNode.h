#define BinNodePosi(T) BinNode<T> *         // 节点位置的指针
#define stature(p) ((p) ? (p)->height : -1) // 节点高度，空树高度为-1， 如果只有根节点，高度是0

// 使用宏定义常用功能
/*
BinNode状态与性质判断
*/

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (!IsRoot(x)) // 不是根节点一定有父节点
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))     // 至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x)) // 同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))

// sibling=兄弟姐妹 找p的兄弟姐妹
#define sibling(p) (IsLChild(*(p)) ? (p)->parent->rc : (p)->parent->lc)
// 找叔叔
#define uncle(x) (IsLChild(*((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)
// 来自父亲的引用
#define FromParentTo(x) \
    (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lc : (x)->parent->rc))

typedef enum
{
    RB_RED,
    RB_BLACK
} RBCOLOR;

// 二叉树节点模板类
template <typename T>
struct BinNode
{
    T data;
    // 父节点、左节点和右节点
    BinNodePosi(T) parent;
    BinNodePosi(T) lc;
    BinNodePosi(T) rc;

    int height; // 高度
    int npl;    // 左式堆

    RBColor color; // 红黑树节点颜色

    // 构造函数
    BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}

    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
            int h = 0, int l = 1, RBColor c = RB_RED) : data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

    // 操作接口
    int size(); // 统计当前节点后代总数
    BinNodePosi(T) insertAsLC(T const &);
    BinNodePosi(T) insertAsRC(T const &);
    BinNodePosi(T) succ();

    template <typename VST>
    void travLevel(VST &); // 层次遍历(队列)
    template <typename VST>
    void travPre(VST &); // 先序遍历 (递归和调用栈、直接后继)
    template <typename VST>
    void travIn(VST &); // 中序遍历 (递归和调用栈、直接后继)
    template <typename VST>
    void travPost(VST &); // 后序遍历 (递归和调用栈、直接后继)

    // 比较器、判等器，运算符重载
    bool operator<(BinNode const &bn) { return data < bn.data; }   // 小于
    bool operator==(BinNode const &bn) { return data == bn.data; } // 等于
};
