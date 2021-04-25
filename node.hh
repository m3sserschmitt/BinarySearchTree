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
protected:
    Node *p;     // parintele nodului;
    Node *left;  // copilul stang;
    Node *right; // copilul drept;
    int key;     // cheia nodului;

public:
    Node();
    Node(int x);
    Node(const Node &node);
    virtual ~Node();

    // returneaza nodul parinte;
    const Node *get_parent() const;

    // returneaza copilul stang;
    const Node *get_left() const;

    // returneaza copilul drept;
    const Node *get_right() const;

    // seteaza parintele;
    void set_parent(const Node *node);

    // seteaza copilul stang;
    void set_left(const Node *node);

    // seteaza copilul drept;
    void set_right(const Node *node);

    // returneaza cheia nodului;
    int get_key() const;

    // seteaza cheia nodului;
    void set_key(int key);

    Node &operator=(const Node &node);
    Node &operator=(int key);

    friend std::ostream &operator<<(std::ostream &out, const Node &node);
    friend std::istream &operator>>(std::istream &in, Node &node);
};

#endif
