#ifndef __PREDICTIONS_H__

#define __PREDICTIONS_H__

#include <map>
#include <vector>
#include <utility>

using namespace std;

typedef map<int, float> Predictions;

void combine(Predictions & dest, Predictions & source);

vector< pair<int, float> > getTop(Predictions & src, unsigned int count);

#endif
