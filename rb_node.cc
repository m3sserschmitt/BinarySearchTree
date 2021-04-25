#include "rb_node.hh"

RedBlackNode::RedBlackNode() : Node()
{
    this->color = RED;
}

RedBlackNode::RedBlackNode(int x) : Node(x)
{
    this->color = RED;
}

RedBlackNode::RedBlackNode(int x, NodeColor color): Node(x)
{
    this->color = color;
}

RedBlackNode::RedBlackNode(const RedBlackNode &node) : Node(node)
{
    this->color = node.color;
}

RedBlackNode::RedBlackNode(const Node &node): Node(node)
{
    this->color = RED;
}

NodeColor RedBlackNode::get_color() const
{
    return this->color;
}

void RedBlackNode::set_color(NodeColor color)
{
    this->color = color;
}

RedBlackNode &RedBlackNode::operator=(const RedBlackNode &node)
{
    Node::operator=(node);
    if (this != &node)
    {
        this->color = node.color;
    }

    return *this;
}

RedBlackNode &RedBlackNode::operator=(int x)
{
    Node::operator=(x);
    this->color = RED;

    return *this;
}
