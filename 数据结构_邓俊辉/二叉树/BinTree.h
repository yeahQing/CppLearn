#include "BinNode.h"

template <typename T> class BinTree {
protected:
    int _size; // 规模
    BinNodePosi(T) _root; // 根节点
    virtual int updateHeight(BinNodePosi(T) x); // 更新节点x的高度
    void updateHeightAbove(BinNodePosi(T) x); // 更新节点x极其祖先的高度
public:
    BinTree(): _size(0), _root(NULL) {}
    ~BinTree() { if (0 < _size) remove(_root); }

    int size() const {return _size;}
    bool empty() const {return !_root;}

    BinNodePosi(T) root() const {return _root;}

    BinNodePosi(T) insertAsRoot(T const& e);
    BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);
    BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);

    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* &T); // T作为x左子树接入
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* &T); // T作为x右子树接入

    int remove(BinNodePosi(T) x); // 删除以位置x处节点为根的子树，返回该子树原先的规模
    BinTree<T>* secede(BinNodePosi(T) x); // 将子树x从当前树种摘除，并将其转换为一颗独立子树

    // 层次遍历
    template<typename VST>
    void travLevel (VST& visit) {
        if (_root) _root->travLevel(visit);
    }

    // 先序遍历
    template<typename VST>
    void travPre (VST& visit) {
        if (_root) _root->travPre(visit);
    }

    // 中序遍历
    template<typename VST>
    void travIn(VST& visit) {
        if (_root) _root->travIn(visit);
    }

    // 后序遍历
    template<typename VST>
    void travPost(VST& visit) {
        if (_root) _root->travPost(visit);
    }

    // 重载操作符
    bool operator<(BinTree<T> const& t)
    {
        return _root && t._root && lt (_root, t._root);
    }

    bool operator==(BinTree<T> const& t)
    {
        return _root && t._root && (_root == t._root);
    }

};