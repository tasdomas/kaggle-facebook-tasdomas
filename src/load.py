#!/usr/bin/python

import sys
import csv
import pickle

from collections import defaultdict

#from scipy.sparse import dok_matrix as matrix
#from numpy import int8
#thematrix = matrix((MAX_SIZE, MAX_SIZE), dtype=int8)

reader = csv.reader(open(sys.argv[1], 'rb'),
                    delimiter=',')

pickle_file = open(sys.argv[2], 'wb')

node_inbound = defaultdict(list)
node_outbound = defaultdict(list)

row = reader.next()

for row in reader:
    a = int(row[0])
    b = int(row[1])

    node_inbound[b].append(a)
    node_outbound[a].append(b)

data = {'inbound': node_inbound, 'outbound': node_outbound}
pickle.dump(data, pickle_file)
pickle_file.close()

