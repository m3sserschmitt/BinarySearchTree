#include "binary_tree.hh"

#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
    this->nil = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    this->clear(this->root);
}

const Node *BinarySearchTree::get_root() const
{
    return this->root;
}

std::ostream &BinarySearchTree::in_order_tree_print(std::ostream &out, const Node *x) const
{
    if (x != this->nil)
    {
        this->in_order_tree_print(out, x->get_left());
        out << *x << " ";
        this->in_order_tree_print(out, x->get_right());
    }

    return out;
}

void BinarySearchTree::clear(const Node *x)
{
    // elibereaza recursiv memoria alocata pe fiecare nod;
    if (x != this->nil)
    {
        this->clear(x->get_left());
        this->clear(x->get_right());

        delete x;
    }
}

const Node *BinarySearchTree::search(const Node *x, Node k) const
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

const Node *BinarySearchTree::min(const Node *x) const
{
    while (x->get_left() != this->nil)
        x = x->get_left();

    return x;
}

Node BinarySearchTree::minimum() const
{
    if (this->root == this->nil)
    {
        throw "Tree is empty";
    }

    return *this->min(this->root);
}

const Node *BinarySearchTree::max(const Node *x) const
{
    while (x->get_right() != this->nil)
        x = x->get_right();

    return x;
}

Node BinarySearchTree::maximum() const
{
    if (this->root == this->nil)
    {
        throw "Tree is empty";
    }

    return *this->max(this->root);
}

Node BinarySearchTree::successor(Node x) const
{
    if (this->root == this->nil)
        throw "Tree is empty";

    // cauta nodul cu cheia lui x;
    const Node *node = this->search(this->root, x);

    // eroare, daca nu s-a gasit cheia
    if (node == this->nil)
        throw "Key does not exist";

    // daca avem copil drept
    if (node->get_right() != this->nil)
    {
        return *this->min(node->get_right());
    }

    const Node *y = node->get_parent();

    while (y != this->nil and node == y->get_right())
    {
        node = y;
        y = y->get_parent();
    }

    return *y;
}

Node BinarySearchTree::predecessor(Node x) const
{
    if (this->root == this->nil)
        throw "Tree is empty";

    // cauta nodul cu cheia lui x;
    const Node *node = this->search(this->root, x);

    if (node == this->nil)
        throw "Key does not exist";

    if (node->get_left() != this->nil) // nu are fiu drept
    {
        return *this->max(node->get_left());
    }

    const Node *y = node->get_parent();

    while (y != this->nil and node == y->get_left())
    {
        node = y;
        y = y->get_parent();
    }

    return *y;
}

void BinarySearchTree::insert(Node n)
{
    // pointer la radacina arborelui;
    Node *x = this->root;

    // auxiliar;
    Node *y = nullptr;

    // noul nod care trebuie adaugat, cu cheia
    // corespunzatoare;
    Node *z = new Node(n);

    // traverseaza arborele:
    // la fiecare pas se decide daca merge la stanga sau dreapata
    // comparand cheile, pana cand se ajunge la o frunza;
    while (x != this->nil)
    {
        y = x;
        if (z->get_key() < x->get_key())
        {
            x = (Node *)x->get_left();
        }
        else
        {
            x = (Node *)x->get_right();
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
}

void BinarySearchTree::remove(Node n)
{
}

void BinarySearchTree::clear()
{
    return this->clear(this->root);
}

std::ostream &operator<<(std::ostream &out, const BinarySearchTree &tree)
{
    const Node *root = tree.root;
    return tree.in_order_tree_print(out, root);
}
