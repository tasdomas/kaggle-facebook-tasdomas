#ifndef __WRITER_H__
#define __WRITER_H__

#include <string>
#include <map>

#include "predictions.h"

using namespace std;

void write_predictions(string filename, map<int, Predictions>& predictions);

#endif
