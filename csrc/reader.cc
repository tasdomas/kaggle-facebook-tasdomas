#include "reader.h"

#include <stdlib.h>

#include <iostream>



using namespace std;

void read_graph(string filename, NodeDirectory& nodes)
{
	ifstream input(filename.c_str());
	string a_val, b_val;
	Node temp;
	int a, b;

	if (input.is_open())
	{
		while (input.good())
		{
			getline(input, a_val, ',');
			getline(input, b_val);
			a = atoi(a_val.c_str());
			b = atoi(b_val.c_str());

			if (nodes[a].getId() != a)
			{
				nodes[a].setId(a);
			}
			nodes[a].out(b);

			if (nodes[b].getId() != b)
			{
				nodes[b].setId(b);
			}
			nodes[b].in(a);

		}
		input.close();
	}

}
