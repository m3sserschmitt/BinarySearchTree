/**
 * @file node.h
 * @brief Clasa Node memoreaza datele(parintele, copiii si cheia) unui nod din arbore;
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef NODE_HH
#define NODE_HH

#include <ostream>
#include <istream>

template <class T>
class Node
{
protected:
    Node *p;     // parintele nodului;
    Node *left;  // copilul stang;
    Node *right; // copilul drept;
    T key;       // cheia nodului;

public:
    Node();
    Node(T x);
    Node(const Node &node);
    virtual ~Node();

    // returneaza nodul parinte;
    const Node<T> *get_parent() const;

    // returneaza copilul stang;
    const Node<T> *get_left() const;

    // returneaza copilul drept;
    const Node<T> *get_right() const;

    // seteaza parintele;
    void set_parent(const Node<T> *node);

    // seteaza copilul stang;
    void set_left(const Node<T> *node);

    // seteaza copilul drept;
    void set_right(const Node<T> *node);

    // returneaza cheia nodului;
    T get_key() const;

    // seteaza cheia nodului;
    void set_key(T key);

    Node<T> &operator=(const Node<T> &node);
    Node<T> &operator=(T key);

    operator T() const;

    template <class t>
    friend std::ostream &operator<<(std::ostream &out, const Node<t> &node);

    template <class t>
    friend std::istream &operator>>(std::istream &in, Node<t> &node);
};

template <class T>
Node<T>::Node()
{
    this->p = nullptr;
    this->left = nullptr;
    this->right = nullptr;
}

template <class T>
Node<T>::Node(T key)
{
    this->p = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->key = key;
}

template <class T>
Node<T>::Node(const Node<T> &node)
{
    this->p = node.p;
    this->left = node.left;
    this->right = node.right;
    this->key = node.key;
}

template <class T>
Node<T>::~Node() {}

template <class T>
const Node<T> *Node<T>::get_parent() const
{
    return this->p;
}

template <class T>
const Node<T> *Node<T>::get_left() const
{
    return this->left;
}

template <class T>
const Node<T> *Node<T>::get_right() const
{
    return this->right;
}

template <class T>
void Node<T>::set_parent(const Node<T> *node)
{
    this->p = (Node *)node;
}

template <class T>
void Node<T>::set_left(const Node<T> *node)
{
    this->left = (Node *)node;
}

template <class T>
void Node<T>::set_right(const Node<T> *node)
{
    this->right = (Node *)node;
}

template <class T>
T Node<T>::get_key() const
{
    return this->key;
}

template <class T>
void Node<T>::set_key(T x)
{
    this->key = key;
}

template <class T>
Node<T>::operator T() const
{
    return this->key;
}

template <class T>
Node<T> &Node<T>::operator=(const Node<T> &node)
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

template <class T>
Node<T> &Node<T>::operator=(T x)
{
    this->p = nullptr;
    this->left = nullptr;
    this->right = nullptr;
    this->key = x;

    return *this;
}

template <class t>
std::ostream &operator<<(std::ostream &out, const Node<t> &node)
{
    out << node.get_key();

    return out;
}

template <class t>
std::istream &operator>>(std::istream &in, Node<t> &node)
{
    int x;
    in >> x;

    node.set_key(x);

    return in;
}

#endif
