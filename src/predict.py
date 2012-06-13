import csv
import sys
import pickle

input = csv.reader(open(sys.argv[1], 'rb'), delimiter=',')
output = csv.writer(open(sys.argv[2], 'wb'), delimiter=',')
row = input.next()

data = pickle.load(open(sys.argv[3], 'rb'))

for row in input:
    node = int(row[0])
    node_in = set(data['inbound'][node])
    node_out = set(data['outbound'][node])

    diff = node_in - node_out
    diff_sorted = sorted(list(diff), key=lambda n: len(data['inbound'][n]))
    diff = diff_sorted[:10]

    output.writerow([str(node), ' '.join(map(str, diff))])
