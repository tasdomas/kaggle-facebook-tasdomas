import csv
import sys
import pickle

import matplotlib.pyplot as plt

input = csv.reader(open(sys.argv[1], 'rb'), delimiter=',')
output = csv.writer(open(sys.argv[2], 'wb'), delimiter=',')
row = input.next()

data = pickle.load(open(sys.argv[3], 'rb'))
inbound = data['inbound']
outbound = data['outbound']

def plot_histo(dt, titles):
    plt.hist(dt, label=titles, bins=50)
    plt.legend()
    plt.show()


def true_F(node):
    global inbound
    global outbound
    return set(inbound[node]).intersection(outbound[node])


def true_FOF(node):
    global outbound
    FOF = set()
    true_f = true_F(node)
    for f in true_f:
        FOF = FOF | true_F(f)
    FOF = FOF - set(outbound[node])
    return FOF

predicted = []
predicted_missing = []
predicted_friends = []
for row in input:
    node = int(row[0])
    node_in = set(data['inbound'][node])
    node_out = set(data['outbound'][node])

    diff = list(node_in - node_out)
    diff_sorted = sorted(diff, key=lambda n: len(data['inbound'][n]))

    predicted_missing.append(len(diff))

    true_friends = true_FOF(node)
    predicted_friends.append(len(true_friends))

    diff.extend(list(true_friends))

    output.writerow([str(node), ' '.join(map(str, diff[:10]))])
    predicted.append(len(diff))

plot_histo([predicted, predicted_missing, predicted_friends],
          ["total", "backlinks", "FOF"])
