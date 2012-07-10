class Node:
    id = None
    in = []
    out = []
    true_friends = None

    def __init__(self, id, in=[], out=[]):
        self.id = id
        self.in = in
        self.out = out

    def trueFriends(self):
        if (self.true_friends is None):
            self.true_friends = self.in.intersect(self.out)
        return self.true_friends
