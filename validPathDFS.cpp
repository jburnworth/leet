#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <stack>

using namespace std;

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    // Make a vector for each node to hold all the nodes that are adjacent to it.
    vector<vector<int>> adjacentVertexes(n);

    for (int i = 0; i < edges.size(); i++) {
        // Store that ui is connected to vi
        adjacentVertexes[edges[i][0]].push_back(edges[i][1]);
        // Store that vi is connected to ui
        adjacentVertexes[edges[i][1]].push_back(edges[i][0]);
        //cout << edges[i][0] << " " << edges[i][1] << endl;
    }

    // Make a stack to hold paths as vectors.
    stack<int> pathStack;
    // Use an unordered set to store visited vertexes
    unordered_set<int> visited;

    // Prime the stack with the source vertex
    pathStack.push(source);

    while (!pathStack.empty()) {
        // Pop the top of the stack
        int topIndex = pathStack.top();
        pathStack.pop();
        // Mark that vertex visited
        visited.insert(topIndex);

        // Check if we made it to the destination.
        if (topIndex == destination) {
            return true;
        }

        // Find the adjacent vertexes and add them to the stack
        for (auto adjacent: adjacentVertexes[topIndex]) {
            if (visited.count(adjacent) == 0) {
                //cout << adjacent << " ";
                pathStack.push(adjacent);
            }
        }
    }

    /*for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto adjacents: adjacentVertexes[i]) {
            cout << adjacents << " ";
        }
        cout << endl;
    }*/
    return false;
}

int main()
{
    // n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
    int vertexes = 9;
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3},{1,3},{1,6},{1,7},{3,8}};
    int source = 1;
    int destination = 5;

    //cout << "Hello" << endl;

    cout << boolalpha;
    cout << "The path is valid? " << validPath(vertexes, edges, source, destination) << endl;

    return 0;
}