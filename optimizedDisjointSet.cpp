#include <iostream>
#include <vector>

using namespace std;

class UnionFindQuickUnion {
private:
    vector<int> root;
    vector<int> rank;

public:
    UnionFindQuickUnion(int size) : root(size), rank(size) {
        for(int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }
    // Find returns the root index of the passed in index. This implementation
    // of find includes path compression via recursion.
    int find(int x) {
        if (root[x] == x) {
            return x;
        }
        return root[x] = find(root[x]);
    }
    // Union takes two indexes and makes their root node the same.  This
    // is an implementation of quick union with union by rank optimization.
    void unionPair(int x, int y) {
        // We only need to union them if they aren't already connected.
        int rootOfX = find(x);
        int rootOfY = find(y);
        if (rootOfX != rootOfY) {
            if (rank[rootOfX] > rank[rootOfY]) {
                root[rootOfY] = rootOfX;
            } else if (rank[rootOfX] < rank[rootOfY]) {
                root[rootOfX] = rootOfY;
            } else {
                root[rootOfY] = rootOfX;
                rank[rootOfX] += 1;
            }
        }
    }
    // Connected returns true if the to indexes have the same root index,
    // meaning they are in the same set.
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int main()
{
    UnionFindQuickUnion disjointSet(10);
    cout << boolalpha;
    // 1-2-5-6-7 3-8-9 4
    disjointSet.unionPair(1, 2);
    disjointSet.unionPair(2, 5);
    disjointSet.unionPair(5, 6);
    disjointSet.unionPair(6, 7);
    disjointSet.unionPair(3, 8);
    disjointSet.unionPair(8, 9);
    cout << disjointSet.connected(1, 5) << endl;
    cout << disjointSet.connected(3, 9) << endl;
    cout << disjointSet.connected(4, 9) << endl;
    // 1-2-5-6-7 3-8-9-4
    disjointSet.unionPair(4, 9);
    cout << disjointSet.connected(4, 9) << endl;

    return 0;
}