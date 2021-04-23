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

class BinarySearchTree
{
    Node *root; // radacina arborelui;

public:
    // metodele din cerinta;
    
    void insert(int x);
    void remove(int x);

    int min() const;
    int max() const;
    
    int successor(int x) const;
    int predecessor(int x) const;

    int kth_element(int k) const;
    int size() const;

    bool exists(int x) const;
};

#endif
