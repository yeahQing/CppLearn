#include "BinNode.h"
#include <stack>
#include <queue>

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const& e)
{
    // 当前节点是this, 插入的节点值是e this->lc=new BinNode
    return lc = new BinNode(e, this);
}

template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const& e)
{
    // 当前节点是this, 插入的节点值是e this->rc=new BinNode
    return rc = new BinNode(e, this);
}

// 先序遍历选择器
template <typename T> template <typename VST> // T:元素类型 VST: 操作器
void BinNode<T>::travPre(VST& visit)
{
    switch (rand() % 3)
    {
        case 1:
            travPre_I1(this, visit);
            break;
        case 2:
            travPre_I2(this, visit);
            break;
        default:
            travPre_R(this, visit);
            break;
    }
}

// 先序遍历的迭代版本1
template <typename T, typename VST>
void travPre_I1(BinNodePosi(T) x, VST& visit)
{
    // 辅助栈
    std::stack<BinNodePosi(T)> s;
    if (x) s.push(x);
    while (!s.empty())
    {
        x = s.top();
        s.pop();
        visit(x->data);
        if (HasRChild(*x)) s.push(x->rc);
        if (HasLChild(*x)) s.push(x->lc);
    }
}

// 先序遍历的迭代版本2
template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, std::stack<BinNodePosi(T)>& s)
{
    while (x)
    {
        visit(x->data);
        s.push(x->rc);
        x = x->lc;
    }
}

template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST& visit)
{
    std::stack<BinNodePosi(T)> s;
    while (true)
    {
        visitAlongLeftBranch(x, visit, s);
        if (s.empty()) break;
        x = s.top(); s.pop();
    }
}

//递归的先序遍历
template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST& visit)
{
    if (!x) return;
    visit(x->data);
    travPre_R(x->lc, visit);
    travPre_R(x->rc, visit);
}

// 中序遍历选择器
template <typename T> template <typename VST>
void BinNode<T>::travIn( VST& visit) {
    switch (rand() % 5)
    {
    case 1:
        travIn_I1(this, visit)
        break;
    case 2:
        travIn_I2(this, visit)
        break;
    case 3:
        travIn_I3(this, visit)
        break;
    case 4:
        travIn_I4(this, visit)
        break;
    default:
        travIn_R(this, visit);
        break;
    }
}

// 中序遍历的迭代版本1
template <typename T>
static void goAlongLeftBranch(BinNodePosi(T) x, std::stack<BinNodePosi(T)> s)
{
    while (x) {
        s.push(x);
        x = x->lc;
    }
}

template <typename T, typename VST>
void travIn_I1(BinNodePosi(T) x, VST& visit)
{
    std::stack<BinNodePosi(T)> s;
    while (true) 
    {
        goAlongLeftBranch(x, s);
        if (s.empty()) break;
        x = s.top(); s.pop(); visit(x->data);
        x = x->rc;
    }
}

// a b c d e f g 中序遍历
// b a f d c e g 先序遍历
// a c e d g f b 后序遍历
/*
    b
a        f
      d       g
    c   e
*/
// 定位任一节点在中序遍历中的直接后继
template <typename T> BinNodePosi(T) BinNode<T>::succ()
{
    BinNodePosi(T) s = this;
    if (rc) {  // 若有右孩子，则直接后继必在右子树中
        s = rc;
        while (HasLChild(*s)) s = s->lc;
    }
    else
    { // 否则，直接后继应是将当前节点包含于其左子树中的最低祖先
        while (IsRChild(*s)) s = s->parent;
        s = s->parent; // 最后再朝右上方移动一步，即抵达直接后继
    }
    return s;
}

// 中序遍历的迭代版本2
template <typename T, typename VST>
void travIn_I2(BinNodePosi(T) x, VST& visit)
{
    std::stack<BinNodePosi(T)> s;
    while (true)
    {
        if (x)
        {
            s.push(x);
            x = x->lc;
        }
        else if (!s.empty())
        {
            x = s.top() s.pop() visit(x);
            x = x->rc;
        }
        else break;
    }
}

// 中序遍历的迭代版本3 不需要辅助栈
template <typename T, typename VST>
void travIn_I3(BinNodePosi(T) x, VST& visit)
{
    bool backtrack = false;
    while (true)
    {
        if (!backtrack && HasLChild(*x))
            x = x->lc;
        else {
            visit(x->data);
            if (HasRChild(*x)) // 若右子树非空
            {
                x = x->rc;
                backtrack = false;
            }
            else { // 若右子树为空
                // 遍历到了中序遍历的末节点，末节点的直接后继为NULL
                if (! (x = x->succ())) break;
                backtrack = true;
            }
        }
    }
}

// 中序遍历的迭代版本4 不需要辅助栈也不需要标志位
template <typename T, typename VST>
void travIn_I4(BinNodePosi(T) x, VST& visit)
{
    while (true)
    {
        if (HasLChild(*x))
        {
            x = x->lc;
        }
        else
        {
            visit(x->data);
            while(!HasRChild(*x)) // 如果没有右,就回溯到直接后继
            {
                if (!(x = x->succ())) return;
                else visit(x->data);
            }
            x = x->rc;
        }
    }
}

//递归的中序遍历
template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST& visit)
{
    if (!x) return;
    travIn_R(x->lc, visit);
    visit(x->data);
    travIn_R(x->rc, visit);
}

// 后序遍历选择器
template <typename T> template <typename VST> // T:元素类型 VST: 操作器
void BinNode<T>::travPost(VST& visit)
{
    switch (rand() % 2)
    {
        case 1:
            travPost_I(this, visit);
            break;
        default:
            travPost_R(this, visit);
            break;
    }
}

// 后序遍历的迭代版本
template <typename T>
static void gotoHLVFL (std::stack<BinNodePosi(T)>& s)
{
    while (BinNodePosi(T) x = s.top())
    {
        if (HasLChild(*x))
        {
            if (HasRChild(*x)) s.push(x->rc); // 若有右孩子，优先入栈
            s.push(x->lc); // 然后才转至左孩子
        }
        else
        {
            s.push(x->rc);
        }
    }
    s.pop();
}

template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST& visit)
{
    std::stack<BinNodePosi(T)> s;
    // 根节点最后输出，入栈
    if (x) s.push(x);
    while (!s.empty())
    {
        if (s.top() != x->parent) // 若栈顶非当前节点之父，则必为其右兄
        {
            gotoHLVFL(s); // 在以其右兄为根之子树中，找到HLVFL
        }
        // 弹出栈顶，即前一节点之后继，并访问之
        x = s.top(); s.pop(); visit(x->data);
    }
}

//递归的后序遍历
template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST& visit)
{
    if (!x) return;
    travPost_R(x->lc, visit);
    travPost_R(x->rc, visit);
    visit(x->data);
}

// 层次遍历
template <typename T> template <typename VST>
void BinNode<T>::travLevel(VST& visit)
{
    std::queue<BinNodePosi(T)> q;
    q.push(this);
    while (!q.empty())
    {
        BinNodePosi(T) x = q.front(); q.pop();
        visit(x->data);
        if (HasLChild(*x)) q.push(x->lc);
        if (HasRChild(*x)) q.push(x->rc);
    }
}