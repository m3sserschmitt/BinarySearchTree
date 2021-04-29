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

template <class T>
class BinarySearchTree
{
    // printeaza nodurile arborelui in ordine crescatoare
    // pornind de la un anumit nod;
    std::ostream &in_order_tree_print(std::ostream &out, const Node<T> *x, bool &c) const;

    void clear(const Node<T> *x);

protected:
    // radacina arborelui;
    Node<T> *root;

    // pentru compatibilitate, in cazul unui arbore simplu va fi nullptr,
    // iar pt rb-tree, pointeaza catre un tip special de nod, de culoare BLACK;
    Node<T> *nil;

    // numarul de elemente;
    size_t count;

    // muta nodul v in locul nodului u
    // (deci tot subarborele cu radacina in v este "transportat" in locul nodului u)
    void transplant(Node<T> *u, Node<T> *v);

public:
    BinarySearchTree();
    virtual ~BinarySearchTree();

    // returneaza radacina arborelui;
    const Node<T> *get_root() const;

    // cauta nodul cu cheia k din subarborele cu radacina x;
    const Node<T> *search(const Node<T> *x, Node<T> k) const;

    // insereaza nodul x in arbore;
    const Node<T> *insert(Node<T> *x);

    // returneaza nodul cu cheia minima din subarborele cu radacina in nodul x;
    const Node<T> *minimum(const Node<T> *x) const;

    // returneaza nodul cu cheia maxima din subarborele cu radacina in nodul x;
    const Node<T> *maximum(const Node<T> *x) const;

    // returneaza nodul succesor al nodului x;
    const Node<T> *successor(const Node<T> *x) const;

    // returneaza nodul predecesor nodului x;
    const Node<T> *predecessor(const Node<T> *x) const;

    // elibereaza recursiv memoria pentru toate nodurile arborelui;
    void clear();

    /*
     * Metodele din cerinta proiectului;
     */

    // insereaza o noua cheie in arbore;
    virtual void insert(Node<T> x);

    // sterge o cheie din arbore;
    virtual void remove(Node<T> x);

    // returneaza minimul din intregul arbore;
    Node<T> minimum() const;

    // returneaza maximul din intregul arbore;
    Node<T> maximum() const;

    // returneaza succesorul lui x;
    Node<T> successor(Node<T> x) const;

    // returneaza predecesorului lui x;
    Node<T> predecessor(Node<T> x) const;

    // returneaza elementul cu indexul k in ordine crescatoare;
    Node<T> kth_element(int k) const;

    // returneaza numarul de noduri din arbore;
    size_t size() const;

    // returneaza true daca nodul x exista in arbore, altfel false;
    bool exists(Node<T> x) const;

    template <class t>
    friend std::ostream &operator<<(std::ostream &out, const BinarySearchTree<t> &tree);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
    this->root = nullptr;
    this->nil = nullptr;
    this->count = 0;
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    this->clear(this->root);
}

template <class T>
const Node<T> *BinarySearchTree<T>::get_root() const
{
    return this->root;
}

template <class T>
void BinarySearchTree<T>::transplant(Node<T> *u, Node<T> *v)
{
    // parintele nodului u
    Node<T> *u_parent = (Node<T> *)u->get_parent();

    // daca u nu are parinte inseamna ca e radacina
    // deci v devine noua radacina
    if (u->get_parent() == this->nil)
    {
        this->root = v;
    }
    // daca u este copil stang
    // atunci v devine copil stang pentru parintele lui u;
    else if (u == u_parent->get_left())
    {
        u_parent->set_left(v);
    }
    // altfel, v devine copil drept pentru parintele lui u;
    else
    {
        u_parent->set_right(v);
    }

    // daca v e nenul, atunci parintele lui u devine parintele lui v;
    if (v != this->nil)
    {
        v->set_parent(u->get_parent());
    }
}

template <class T>
std::ostream &BinarySearchTree<T>::in_order_tree_print(std::ostream &out, const Node<T> *x, bool &c) const
{
    if (x != this->nil)
    {
        // se parcurge recursiv arborele pana la nodul
        // cu cheia cea mai mica;
        this->in_order_tree_print(out, x->get_left(), c);

        // initial c = 0, deci nu se printeaza virgula
        if (c)
        {
            out << ", ";
        } // dupa ce se printeza primul nod, c devine 1
        // deci la urmatorul apel va printa si virgula
        else
        {
            c = 1;
        }

        out << *x;

        this->in_order_tree_print(out, x->get_right(), c);
    }

    return out;
}

template <class T>
const Node<T> *BinarySearchTree<T>::search(const Node<T> *x, Node<T> k) const
{
    while (x != this->nil and k != x->get_key())
    {
        if (k < x->get_key())
        {
            x = x->get_left();
        }
        else
        {
            x = x->get_right();
        }
    }

    return x;
}

template <class T>
const Node<T> *BinarySearchTree<T>::insert(Node<T> *z)
{
    // pointer la radacina arborelui;
    Node<T> *x = this->root;

    // auxiliar;
    Node<T> *y = this->nil;

    // traverseaza arborele:
    // la fiecare pas se decide daca merge la stanga sau dreapata
    // comparand cheile, pana cand se ajunge la o frunza;
    while (x != this->nil)
    {
        y = x;
        if (z->get_key() < x->get_key())
        {
            x = (Node<T> *)x->get_left();
        }
        else
        {
            x = (Node<T> *)x->get_right();
        }
    }

    // seteaza parintele lui z;
    z->set_parent(y);

    // daca arborele nu a avut radacina
    if (y == this->nil)
    {
        // atunci z devine radacina;
        this->root = z;
    }
    // altfel se decide daca z este copilul drept sau stang al lui y,
    // comparand cheile;
    else if (z->get_key() < y->get_key())
    {
        y->set_left(z);
    }
    else
    {
        y->set_right(z);
    }

    this->count++;

    return z;
}

template <class T>
const Node<T> *BinarySearchTree<T>::minimum(const Node<T> *x) const
{
    while (x->get_left() != this->nil)
        x = x->get_left();

    return x;
}

template <class T>
const Node<T> *BinarySearchTree<T>::maximum(const Node<T> *x) const
{
    while (x->get_right() != this->nil)
        x = x->get_right();

    return x;
}

template <class T>
const Node<T> *BinarySearchTree<T>::successor(const Node<T> *x) const
{
    // daca avem copil drept
    if (x->get_right() != this->nil)
    {
        return this->minimum(x->get_right());
    }

    const Node<T> *y = x->get_parent();

    while (y != this->nil and x == y->get_right())
    {
        x = y;
        y = y->get_parent();
    }

    return y;
}

template <class T>
const Node<T> *BinarySearchTree<T>::predecessor(const Node<T> *x) const
{
    if (x->get_left() != this->nil)
    {
        return this->maximum(x->get_left());
    }

    const Node<T> *y = x->get_parent();

    while (y != this->nil and x == y->get_left())
    {
        x = y;
        y = y->get_parent();
    }

    return y;
}

template <class T>
void BinarySearchTree<T>::clear(const Node<T> *x)
{
    // elibereaza recursiv memoria alocata pe fiecare nod;
    if (x != this->nil)
    {
        this->clear(x->get_left());
        this->clear(x->get_right());

        delete x;
    }
}

template <class T>
void BinarySearchTree<T>::insert(Node<T> n)
{
    // noul nod care va fi inserat;
    Node<T> *z = new Node<T>(n);

    this->insert(z);
}

template <class T>
void BinarySearchTree<T>::remove(Node<T> n)
{
}

template <class T>
Node<T> BinarySearchTree<T>::minimum() const
{
    if (this->root == this->nil)
    {
        throw "Tree is empty";
    }

    return *this->minimum(this->root);
}

template <class T>
Node<T> BinarySearchTree<T>::maximum() const
{
    if (this->root == this->nil)
    {
        throw "Tree is empty";
    }

    return *this->maximum(this->root);
}

template <class T>
Node<T> BinarySearchTree<T>::successor(Node<T> x) const
{
    if (this->root == this->nil)
        throw "Tree is empty";

    // cauta nodul cu cheia lui x;
    const Node<T> *z = this->search(this->root, x);

    // eroare, daca nu s-a gasit cheia
    if (z == this->nil)
        throw "Key does not exist";

    const Node<T> *x_successor = this->successor(z);

    if (x_successor == this->nil)
    {
        throw "Successor does not exist";
    }

    return *x_successor;
}

template <class T>
Node<T> BinarySearchTree<T>::predecessor(Node<T> x) const
{
    if (this->root == this->nil)
        throw "Tree is empty";

    // cauta nodul cu cheia lui x;
    const Node<T> *z = this->search(this->root, x);

    if (z == this->nil)
        throw "Key does not exist";

    if (z->get_left() != this->nil)
    {
        return *this->maximum(z->get_left());
    }

    const Node<T> *x_predecessor = this->predecessor(z);

    if (x_predecessor == this->nil)
    {
        throw "Predecessor does not exists";
    }

    return *x_predecessor;
}

template <class T>
size_t BinarySearchTree<T>::size() const
{
    return this->count;
}

template <class T>
void BinarySearchTree<T>::clear()
{
    return this->clear(this->root);
}

template <class t>
std::ostream &operator<<(std::ostream &out, const BinarySearchTree<t> &tree)
{
    const Node<t> *root = tree.root;

    // la primul apel nu se printeaza virgula
    bool c = 0;

    out << "{";
    tree.in_order_tree_print(out, root, c);
    out << "}";

    return out;
}

#endif
