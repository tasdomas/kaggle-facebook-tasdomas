#include "writer.h"
#include "predictions.h"

#include <fstream>

using namespace std;

void write_predictions(string filename, map<int, Predictions>& predictions)
{
	ofstream output(filename.c_str());

	if (output.is_open())
	{
		map<int, Predictions>::iterator it;
		for (it = predictions.begin(); it != predictions.end(); it++)
		{
			int cnt = 0;
			output << it->first << ",";
			vector< pair<int, float> > top = getTop(it->second, 10);
			vector< pair<int, float> >::iterator p_it;
			for (p_it = top.begin(); (p_it != top.end()); p_it++)
			{
				output << " " << p_it->first;
				cnt++;
			}
			output << endl;
		}
		output.close();
	}
}
