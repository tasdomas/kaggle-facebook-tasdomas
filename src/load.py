#!/usr/bin/python

import sys
import csv
import pickle
import argparse

from collections import defaultdict

parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('dataset', type=str)
parser.add_argument('storage', type=str)

args = parser.parse_args()



#from scipy.sparse import dok_matrix as matrix
#from numpy import int8
#thematrix = matrix((MAX_SIZE, MAX_SIZE), dtype=int8)

reader = csv.reader(open(args.dataset, 'rb'),
                    delimiter=',')

pickle_file = open(args.storage, 'wb')

node_inbound = defaultdict(list)
node_outbound = defaultdict(list)
node_weights_out = defaultdict(float)
node_weights_in = defaultdict(float)

row = reader.next()

for row in reader:
    a = int(row[0])
    b = int(row[1])

    node_inbound[b].append(a)
    node_outbound[a].append(b)
    node_weights_in[b] += 1
    node_weights_out[a] += 1

data = {'inbound': node_inbound,
        'outbound': node_outbound,
        'weights_out': node_weights_out,
        'weights_in': node_weights_in}
pickle.dump(data, pickle_file)
pickle_file.close()

