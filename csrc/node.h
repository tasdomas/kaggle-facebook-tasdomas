#ifndef __NODE_H__
#define __NODE_H__

#include <vector>

#include "node_relation.h"

using namespace std;

class Node
{
private:
	int id;
	vector<NodeRelation> in;
	vector<NodeRelation> out;
	int count_in;
	int count_out;
public:
	explicit Node(int id);
	~Node();
};

#endif
