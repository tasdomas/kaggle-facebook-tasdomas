#include "node.h"

#include <iostream>
#include <algorithm>
#include <iterator>

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

Predictions Node::missedBacklinks(NodeDirectory& context)
{
	set<int> diff;
	Predictions result;
	set_difference(this->links_in.begin(),
		this->links_in.end(),
		this->links_out.begin(),
		this->links_out.end(),
		inserter(diff, diff.end()));

	set<int>::iterator it;

	for (it = diff.begin(); it != diff.end(); it++)
	{
		result[*it] = 1/(float)context[*it].getRankOut();
	}
	return result;
}

int Node::getRankIn()
{
	return this->count_in;
}

int Node::getRankOut()
{
	return this->count_out;
}
