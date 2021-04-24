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
    Node *root; // radacina arborelui;

    // printeaza nodurile arborelui in ordine crescatoare
    // pornind de la un anumit nod;
    std::ostream &in_order_tree_print(std::ostream &out, const Node *node) const;

public:
    // metodele din cerinta;
    
    // returneaza radacina arborelui;
    const Node *get_root() const;
    
    // insereaza o noua cheie in arbore;
    void insert(int key);

    // sterge o cheie din arbore;
    void remove(int key);

    // returneaza cheia minima a arborelui;
    int min() const;

    // returneaza cheia maxima a arborelui;
    int max() const;
    
    // returneaza succesorul;
    int successor(int key) const;

    // returneaza predecesorului;
    int predecessor(int key) const;

    // returneaza elementul cu indexul k in ordine crescatoare;
    int kth_element(int k) const;

    // returneaza numarul de noduri din arbore;
    int size() const;

    // returneaza true daca nodul x exista in arbore, altfel false;
    bool exists(int key) const;

    friend std::ostream &operator<<(std::ostream &out, const BinarySearchTree &tree);
};

#endif
