
def missing_links(node, data):
    node_in = set(data['inbound'][node])
    node_out = set(data['outbound'][node])

    diff = list(node_in - node_out)
    result = sorted(diff, key=lambda n: data['weights_out'], reverse=True)
    return result

