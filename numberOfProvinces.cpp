#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class UnionFindQuickUnion {
private:
    vector<int> root;
    vector<int> rank;

public:
    UnionFindQuickUnion(int size) : root(size), rank(size) {
        for (int i = 0; i < size; i++) {
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
            if (rank[x] > rank[y]) {
                root[y] = rootOfX;
            } else if (rank[x] < rank[y]) {
                root[x] = rootOfY;
            } else {
                root[y] = rootOfX;
                rank[rootOfX] += 1;
            }
        }
        for (int i = 0; i < root.size(); i++) {
            cout << i << ": " << root[i] << ", " << rank[i] << endl;
        }
    }
    // Connected returns true if the to indexes have the same root index,
    // meaning they are in the same set.
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    int citiesNumber = isConnected.size();
    UnionFindQuickUnion disjointCitySet(citiesNumber);

    // Make all the unions in our disjoint set
    for (int i = 0; i < citiesNumber; i++) {
        for (int j = 0; j < citiesNumber; j++) {
            if ((i != j) && (isConnected[i][j] == 1)) {
                cout << "Connecting " << i << " and " << j << endl;
                disjointCitySet.unionPair(i, j);
            }
        }
    }

    // Find all the unique root nodes, or how many sets there are.
    unordered_set<int> provinces;
    for (int i = 0; i < citiesNumber; i++) {
        int aRoot = disjointCitySet.find(i);
        // if the root isn't already in the set, add it!
        if (provinces.find(aRoot) == provinces.end()) {
            cout << "New, unique root: " << aRoot << " for city: " << i << endl;
            provinces.insert(aRoot);
        }
    }
    return provinces.size();
}

int main()
{
    /* UnionFindQuickUnion example use and test code.
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
    */

    //vector<vector<int>> connectionMatrix = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    vector<vector<int>> connectionMatrix = {{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
    int provinceNumber = findCircleNum(connectionMatrix);

    cout << provinceNumber << endl;

    return 0;
}