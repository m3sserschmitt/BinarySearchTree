#include "binary_tree.hh"

const Node *BinarySearchTree::get_root() const
{
    return this->root;
}

std::ostream &BinarySearchTree::in_order_tree_print(std::ostream &out, const Node *node) const
{
    if (node != nullptr)
    {
        
        this->in_order_tree_print(out, node->get_left());
        // node->get_left() and out << *node << ", ";
        out << *node << " ";
        // (node->get_left() or node->get_right()) and out << ", ";
        this->in_order_tree_print(out, node->get_right());
        // node->get_right() and out << *node << ", ";
        
    }

    return out;
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

std::ostream &operator<<(std::ostream &out, const BinarySearchTree &tree)
{
    const Node *root = tree.root;
    return tree.in_order_tree_print(out, root);
}