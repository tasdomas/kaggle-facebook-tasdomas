#ifndef __READER_H__
#define __READER_H__

#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <vector>

#include "node.h"
using namespace std;

void read_graph(string filename, NodeDirectory& nodes);

void read_test(string filename, vector<int>& nodes);

#endif
