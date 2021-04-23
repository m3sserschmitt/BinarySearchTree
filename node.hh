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

class Node 
{
    Node *p;  // parintele nodului;
    Node *left; // copilul stang;
    Node *right;  // copilul drept;
    int key;  // cheia nodului;

public:
    Node();
    Node(int key);
    Node(const Node &node);

    const Node *get_parent() const;
    const Node *get_left() const;
    const Node *get_right() const;

    void set_parent(const Node *node);
    void set_left(const Node *node);
    void set_right(const Node *node);

    int get_key() const;
    void set_key(int key);

    Node &operator=(const Node &node);
    Node &operator=(int key);

    friend std::ostream &operator<<(std::ostream &out, const Node &node);
    friend std::istream &operator>>(std::istream &in, Node &node);
};

#endif
