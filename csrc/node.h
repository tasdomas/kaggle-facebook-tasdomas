#ifndef __NODE_H__
#define __NODE_H__

#include <map>
#include <set>

#include "node_relation.h"
#include "predictions.h"

using namespace std;

class Node;

typedef map<int, Node> NodeDirectory;


class Node
{
private:
	int id;
	set<int> links_in;
	set<int> links_out;
	map<int, float> friends;
	int count_in;
	int count_out;
	//TODO - make NodeDirectory a singleton
	void generateFriends(NodeDirectory& context);

public:
	explicit Node(int id);
	Node();
	~Node();

	int getId();
	void setId(int id);
	void out(int id);
	void in(int id);

	int getRankIn();
	int getRankOut();

	map<int, float> getFriends(NodeDirectory& context);
	map<int, float> getFriendsAll(NodeDirectory& context);

	Predictions missedBacklinks(NodeDirectory& context);
	Predictions friendsOfFriends(NodeDirectory& context);
	Predictions fofAny(NodeDirectory& context);
};

#endif
