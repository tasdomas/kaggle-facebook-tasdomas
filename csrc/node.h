#ifndef __NODE_H__
#define __NODE_H__

#include <map>
#include <set>

#include "node_relation.h"

using namespace std;

class Node
{
private:
	int id;
	set<int> links_in;
	set<int> links_out;
	int count_in;
	int count_out;
public:
	explicit Node(int id);
	Node();
	~Node();

	int getId();
	void setId(int id);
	void out(int id);
	void in(int id);
};

typedef map<int, Node> NodeDirectory;

#endif
