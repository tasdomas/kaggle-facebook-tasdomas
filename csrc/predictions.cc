#include "predictions.h"

#include <utility>
#include <algorithm>

using namespace std;

void combine(Predictions & dest, Predictions & source)
{
	Predictions::iterator it;
	for (it = source.begin(); it != source.end(); it++)
	{
		dest[it->first] += source[it->first];
	}
}

static bool
compare_predictions(pair<int, float> a, pair<int, float> b)
{
	return a.second > b.second;
}

vector< pair<int, float> > getTop(Predictions & src, unsigned int count)
{
	vector< pair<int, float> > parsed;
	Predictions::iterator it;

	for (it = src.begin(); it != src.end(); it++)
	{
		parsed.push_back(*it);
	}
	sort(parsed.begin(), parsed.end(), compare_predictions);
	if (parsed.size() > count)
	{
		parsed.resize(count);
	}
	return parsed;
}
