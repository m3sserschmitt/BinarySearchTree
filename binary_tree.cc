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

void BinarySearchTree::transplant(Node *u, Node *v)
{
    // parintele nodului u
    Node *u_parent = (Node *)u->get_parent();

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

std::ostream &BinarySearchTree::in_order_tree_print(std::ostream &out, const Node *x, bool &c) const
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

const Node *BinarySearchTree::insert(Node *z)
{
    // pointer la radacina arborelui;
    Node *x = this->root;

    // auxiliar;
    Node *y = this->nil;

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

    return z;
}

const Node *BinarySearchTree::minimum(const Node *x) const
{
    while (x->get_left() != this->nil)
        x = x->get_left();

    return x;
}

const Node *BinarySearchTree::maximum(const Node *x) const
{
    while (x->get_right() != this->nil)
        x = x->get_right();

    return x;
}

const Node *BinarySearchTree::successor(const Node *x) const
{
    // daca avem copil drept
    if (x->get_right() != this->nil)
    {
        return this->minimum(x->get_right());
    }

    const Node *y = x->get_parent();

    while (y != this->nil and x == y->get_right())
    {
        x = y;
        y = y->get_parent();
    }

    return y;
}

const Node *BinarySearchTree::predecessor(const Node *x) const
{
    if (x->get_left() != this->nil)
    {
        return this->maximum(x->get_left());
    }

    const Node *y = x->get_parent();

    while (y != this->nil and x == y->get_left())
    {
        x = y;
        y = y->get_parent();
    }

    return y;
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

void BinarySearchTree::insert(Node n)
{
    // noul nod care va fi inserat;
    Node *z = new Node(n);

    this->insert(z);
}

Node BinarySearchTree::minimum() const
{
    if (this->root == this->nil)
    {
        throw "Tree is empty";
    }

    return *this->minimum(this->root);
}

Node BinarySearchTree::maximum() const
{
    if (this->root == this->nil)
    {
        throw "Tree is empty";
    }

    return *this->maximum(this->root);
}

Node BinarySearchTree::successor(Node x) const
{
    if (this->root == this->nil)
        throw "Tree is empty";

    // cauta nodul cu cheia lui x;
    const Node *z = this->search(this->root, x);

    // eroare, daca nu s-a gasit cheia
    if (z == this->nil)
        throw "Key does not exist";

    const Node *x_successor = this->successor(z);

    if (x_successor == this->nil)
    {
        throw "Successor does not exist";
    }

    return *x_successor;
}

Node BinarySearchTree::predecessor(Node x) const
{
    if (this->root == this->nil)
        throw "Tree is empty";

    // cauta nodul cu cheia lui x;
    const Node *z = this->search(this->root, x);

    if (z == this->nil)
        throw "Key does not exist";

    if (z->get_left() != this->nil)
    {
        return *this->maximum(z->get_left());
    }

    const Node *x_predecessor = this->predecessor(z);

    if (x_predecessor == this->nil)
    {
        throw "Predecessor does not exists";
    }

    return *x_predecessor;
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

    // la primul apel nu se printeaza virgula
    bool c = 0;

    out << "{";
    tree.in_order_tree_print(out, root, c);
    out << "}";

    return out;
}
