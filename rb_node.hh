#ifndef RB_NODE_HH
#define RB_NODE_HH

#include "node.hh"

// colorile posibile pentru un nod
enum NodeColor
{
    RED = 0,
    BLACK = 1
};

template <class T>
class RedBlackNode : public Node<T>
{
    // culoarea nodului;
    NodeColor color;

public:
    RedBlackNode();
    RedBlackNode(T x);
    RedBlackNode(T x, NodeColor color);
    RedBlackNode(const RedBlackNode<T> &node);
    RedBlackNode(const Node<T> &node);

    // returneaza culoarea nodului;
    NodeColor get_color() const;

    // seteaza culoarea nodului;
    void set_color(NodeColor color);

    RedBlackNode<T> &operator=(const RedBlackNode<T> &node);
    RedBlackNode<T> &operator=(T x);
};

template <class T>
RedBlackNode<T>::RedBlackNode() : Node<T>()
{
    this->color = RED;
}

template <class T>
RedBlackNode<T>::RedBlackNode(T x) : Node<T>(x)
{
    this->color = RED;
}

template <class T>
RedBlackNode<T>::RedBlackNode(T x, NodeColor color) : Node<T>(x)
{
    this->color = color;
}

template <class T>
RedBlackNode<T>::RedBlackNode(const RedBlackNode<T> &node) : Node<T>(node)
{
    this->color = node.color;
}

template <class T>
RedBlackNode<T>::RedBlackNode(const Node<T> &node) : Node<T>(node)
{
    this->color = RED;
}

template <class T>
NodeColor RedBlackNode<T>::get_color() const
{
    return this->color;
}

template <class T>
void RedBlackNode<T>::set_color(NodeColor color)
{
    this->color = color;
}

template <class T>
RedBlackNode<T> &RedBlackNode<T>::operator=(const RedBlackNode<T> &node)
{
    Node<T>::operator=(node);
    if (this != &node)
    {
        this->color = node.color;
    }

    return *this;
}

template <class T>
RedBlackNode<T> &RedBlackNode<T>::operator=(T x)
{
    Node<T>::operator=(x);
    this->color = RED;

    return *this;
}

#endif
