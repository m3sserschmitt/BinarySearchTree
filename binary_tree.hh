/**
 * @file binary_tree.hh
 * @brief Declaratia pentru binary search tree
 * @version 0.1
 * @date 2021-04-23
 *
 * @copyright Copyright (c) 2021
 *
 */

#ifndef BINARY_TREE_HH
#define BINARY_TREE_HH

#include "node.hh"
#include <ostream>

class BinarySearchTree
{
    // printeaza nodurile arborelui in ordine crescatoare
    // pornind de la un anumit nod;
    std::ostream &in_order_tree_print(std::ostream &out, const Node *x) const;

    void clear(const Node *x);
protected:
    Node *root; // radacina arborelui;

    // pentru compatibilitate, in cazul unui arbore simplu va fi nullptr,
    // iar pt rb-tree, pointeaza catre un tip special de nod, de culoare BLACK;
    Node *nil;

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

    // metodele din cerinta;

    // returneaza radacina arborelui;
    const Node *get_root() const;

    const Node *search(const Node *x, Node k) const;

    // insereaza o noua cheie in arbore;
    virtual void insert(Node x);

    // sterge o cheie din arbore;
    virtual void remove(Node x);

    // returneaza cheia minima a arborelui;
    const Node *min(const Node *x) const;
    Node minimum() const;

    // returneaza cheia maxima a arborelui;
    const Node *max(const Node *x) const;
    Node maximum() const;

    // returneaza succesorul;
    Node successor(Node x) const;

    // returneaza predecesorului;
    Node predecessor(Node x) const;

    // returneaza elementul cu indexul k in ordine crescatoare;
    Node kth_element(int k) const;

    // returneaza numarul de noduri din arbore;
    int size() const;

    // returneaza true daca nodul x exista in arbore, altfel false;
    bool exists(Node x) const;

    // elibereaza memoria pentru toate nodurile arborelui;
    void clear();

    friend std::ostream &operator<<(std::ostream &out, const BinarySearchTree &tree);
};

#endif
