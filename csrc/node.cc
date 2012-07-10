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

map<int, float> Node::getFriends(NodeDirectory& context)
{
	map<int, float> friends;
	float weight = 1.0 / this->getRankOut();

	set<int>::iterator it;

	for (it = this->links_out.begin();
	     it != this->links_out.end();
	     it++)
	{
		friends[*it] = weight;
	}
	return friends;
}

Predictions Node::friendsOfFriends(NodeDirectory& context)
{
	map<int, float> friends = this->getFriends(context);
	Predictions result;

	map<int, float>::iterator it;

	for (it = friends.begin();
	     it != friends.end();
	     it++)
	{
		map<int, float> fof = context[it->first].getFriends(context);
		map<int, float>::iterator fof_it;
		for (fof_it = fof.begin();
		     fof_it != fof.end();
		     fof_it++)
		{
			if ((this->links_out.find(fof_it->first) == this->links_out.end()) &&
				(fof_it->first != this->id))
			{
				result[fof_it->first] += fof_it->second * it->second;
			}
		}
	}
	return result;
}
