#include "binary_tree.hh"

#include <iostream>

using namespace std;

BinarySearchTree::BinarySearchTree()
{
    this->root = nullptr;
}

BinarySearchTree::~BinarySearchTree() 
{
    // this->clear(this->root);
}

const Node *BinarySearchTree::get_root() const
{
    return this->root;
}

std::ostream &BinarySearchTree::in_order_tree_print(std::ostream &out, const Node *x) const
{
    if (x != nullptr)
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
    if (x != nullptr)
    {
        this->clear(x->get_left());
        this->clear(x->get_right());

        delete x;
    }
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
    while (x != nullptr)
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
    if (y == nullptr)
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
