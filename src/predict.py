import csv
import sys
import pickle
import argparse

import matplotlib.pyplot as plt

import predictors

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

for row in input:
    pred = []
    node = int(row[0])
    node_in = set(data['inbound'][node])
    node_out = set(data['outbound'][node])

    missing_links = predictors.missing_links(node, data)

    #true_friends = true_FOF(node)
    #predicted_friends.append(len(true_friends))

    #diff.extend(list(true_friends))

    pred.extend(missing_links)

    output.writerow([str(node), ' '.join(map(str, pred[:10]))])
    #predicted.append(len(diff))

#plot_histo([predicted, predicted_missing, predicted_friends],
#          ["total", "backlinks", "FOF"])
