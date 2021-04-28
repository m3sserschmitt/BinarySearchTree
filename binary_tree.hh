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
    std::ostream &in_order_tree_print(std::ostream &out, const Node *x, bool &c) const;

    void clear(const Node *x);

protected:
    // radacina arborelui;
    Node *root;

    // pentru compatibilitate, in cazul unui arbore simplu va fi nullptr,
    // iar pt rb-tree, pointeaza catre un tip special de nod, de culoare BLACK;
    Node *nil;

    // muta nodul v in locul nodului u
    // (deci tot subarborele cu radacina in v este "transportat" in locul nodului u)
    void transplant(Node *u, Node *v);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

    // returneaza radacina arborelui;
    const Node *get_root() const;

    // cauta nodul cu cheia k din subarborele cu radacina x;
    const Node *search(const Node *x, Node k) const;

    // insereaza nodul x in arbore;
    const Node *insert(Node *x);

    // returneaza nodul cu cheia minima din subarborele cu radacina in nodul x;
    const Node *minimum(const Node *x) const;

    // returneaza nodul cu cheia maxima din subarborele cu radacina in nodul x;
    const Node *maximum(const Node *x) const;

    // returneaza nodul succesor al nodului x;
    const Node *successor(const Node *x) const;

    // returneaza nodul predecesor nodului x;
    const Node *predecessor(const Node *x) const;

    // elibereaza recursiv memoria pentru toate nodurile arborelui;
    void clear();

    /*
     * Metodele din cerinta proiectului;
     */

    // insereaza o noua cheie in arbore;
    virtual void insert(Node x);

    // sterge o cheie din arbore;
    virtual void remove(Node x);

    // returneaza minimul din intregul arbore;
    Node minimum() const;

    // returneaza maximul din intregul arbore;
    Node maximum() const;

    // returneaza succesorul lui x;
    Node successor(Node x) const;

    // returneaza predecesorului lui x;
    Node predecessor(Node x) const;

    // returneaza elementul cu indexul k in ordine crescatoare;
    Node kth_element(int k) const;

    // returneaza numarul de noduri din arbore;
    int size() const;

    // returneaza true daca nodul x exista in arbore, altfel false;
    bool exists(Node x) const;

    friend std::ostream &operator<<(std::ostream &out, const BinarySearchTree &tree);
};

#endif
