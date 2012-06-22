#include "node.h"

Node::Node(int p_id):
	count_in(0), count_out(0)
{
	id = p_id;
}

Node::~Node()
{
}
