#ifndef RB_NODE_HH
#define RB_NODE_HH

#include "node.hh"

// colorile posibile pentru un nod
enum NodeColor
{
    RED = 0,
    BLACK = 1
};

class RedBlackNode : public Node
{
    // culoarea nodului;
    NodeColor color;

public:
    RedBlackNode();
    RedBlackNode(int x);
    RedBlackNode(int x, NodeColor color);
    RedBlackNode(const RedBlackNode &node);

    // returneaza culoarea nodului;
    NodeColor get_color() const;

    // seteaza culoarea nodului;
    void set_color(NodeColor color);

    RedBlackNode &operator=(const RedBlackNode &node);
    RedBlackNode &operator=(int x);
};

#endif
