#include "node.hh"

Node::Node()
{
    this->p = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int key)
{
    this->p = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->key = key;
}

Node::Node(const Node &node)
{
    this->p = node.p;
    this->left = node.left;
    this->right = node.right;
    this->key = node.key;
}

Node::~Node() {}

const Node *Node::get_parent() const
{
    return this->p;
}

const Node *Node::get_left() const
{
    return this->left;
}

const Node *Node::get_right() const
{
    return this->right;
}

void Node::set_parent(const Node *node)
{
    this->p = (Node *)node;
}

void Node::set_left(const Node *node)
{
    this->left = (Node *)node;
}

void Node::set_right(const Node *node)
{
    this->right = (Node *)node;
}

int Node::get_key() const
{
    return this->key;
}

void Node::set_key(int x)
{
    this->key = key;
}

Node::operator int() const
{
    return this->key;
}

Node &Node::operator=(const Node &node)
{
    if (this != &node)
    {
        this->p = node.p;
        this->left = node.left;
        this->right = node.right;
        this->key = node.key;
    }

    return *this;
}

Node &Node::operator=(int x)
{
    this->p = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->key = x;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const Node &node)
{
    out << node.get_key();

    return out;
}

std::istream &operator>>(std::istream &in, Node &node)
{
    int x;
    in >> x;

    node.set_key(x);

    return in;
}
