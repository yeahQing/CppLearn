#include "BinTree.h"

// 更新节点x的高度
template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
    return x->height = 1 + max(stature(x->lc), stature(x->rc));
}

// 更新高度(以节点x为根的子树的高度)
template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
    // 更新全部节点的高度
    while (x)
    {
        updateHeight(x);
        x = x->parent;
    }
}

// 节点插入
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
    _size = 1;
    return _root = new BinNode<T>(e);
}

// 将e插入为x的左孩子
template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{
    _size++;
    x->insertAsLC(e);
    updateHeightAbove(x);
    return x->lc;
}

// 将e插入为x的右孩子
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{
    _size++;
    x->insertAsRC(e);
    updateHeightAbove(x);
    return x->rc;
}

// 子树接入
// 二叉树子树接入算法, 将S作为节点x的左子树接入, S本身置空
template <typename T> BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S)
{
    // 将S的根节点赋值给x的左孩子, 如果S不为空树, 则将x的左的父节点指向x节点
    if (x->lc = S->_root) x->lc->parent = x; // 接入
    // 当前树的规模就变为本来的规模加上S这棵树的规模
    _size += S->_size;
    // 更新全树规模与x所有祖先的高度
    updateHeightAbove(x);
    // 销毁原树
    S->_root = NULL;
    S->_size = 0;
    // 释放S的内存
    release (S);
    S = NULL;
    return x;
}

// 二叉树子树接入算法, 将S作为节点x的右子树接入, S本身置空
template <typename T> BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S)
{
    // 将S的根节点赋值给x的左孩子, 如果S不为空树, 则将x的左的父节点指向x节点
    if (x->rc = S->_root) x->rc->parent = x; // 接入
    // 当前树的规模就变为本来的规模加上S这棵树的规模
    _size += S->_size;
    // 更新全树规模与x所有祖先的高度
    updateHeightAbove(x);
    // 销毁原树
    S->_root = NULL;
    S->_size = 0;
    // 释放S的内存
    release (S);
    S = NULL;
    return x;
}

// 子树删除
// 删除二叉树中位置x处的节点及其后代，返回被删除节点的数值
template <typename T> int BinTree<T>::remove(BinNodePosi(T) x)
{
    // 获得x的父引用，我父亲指向我的指针变为空 x->parent->lc/rc = NULL
    FromParentTo(*x) = NULL;
    updateHeightAbove(x->parent); // 更新祖先的高度
    int n = removeAt(x); _size -= n; return n;
}

template <typename T> static int removeAt(BinNodePosi(T) x)
{
    // assert: x 为二叉树中的合法位置
    if (!x) return 0;
    int n = 1 + removeAt(x->lc) + removeAt(x->rc); // 递归释放左、右子树
    release(x->data); release(x); return n;
}

// 子树分离
template <typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x)
{
    FromParentTo(*x) = NULL; // 切断来自父节点的指针
    updateHeightAbove(x->parent); // 更新原树中所有祖先的高度

    // 新树以x为根
    BinTree<T>* S = new BinTree<T>;
    S->_root = x;
    x->parent = NULL;
    S->_size = x->size();
    // 更新原树的规模
    _size -= S->_size;
    return S;
}