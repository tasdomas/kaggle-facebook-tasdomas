#include "node.h"

#include <iostream>
using namespace std;

Node::Node(int p_id):
	count_in(0), count_out(0)
{
	id = p_id;
}

Node::Node():
	id(-1), count_in(0), count_out(0)
{
}

Node::~Node()
{
	//cout << this->links_in.size() << endl;
}

int Node::getId()
{
	return this->id;
}

void Node::setId(int p_id)
{
	this->id = p_id;
}

void Node::out(int p_id)
{
	//cout << this->id << " -> " << p_id << endl;
	this->links_out.insert(p_id);
	this->count_out++;
}

void Node::in(int p_id)
{
	//cout << this->id << " <- " << p_id << endl;
	this->links_in.insert(p_id);
	this->count_in++;
}
