/**
 * Tree centers are the nodes which are located in the
 * center of the longest path in the tree. They can be
 * found if we eliminate the leaves in a recursive manner.
 * The nodes which will be left in the end will be the center(s)
 * of the tree.
 * 
 * Author : Yatharth Goswami
 * Github ID : yatharth0610
 * Email : yatharthgoswami15@gmail.com
 *
 */

#include <bits/stdc++.h>

using namespace std;

vector <int> findCenters(vector <vector <int>> tree) {
    int n = tree.size();
    vector <int> degree(n), leaves;

    for (int i = 0; i < n; i++) {
        degree[i] = tree[i].size();
        if (degree[i] <= 1) {
            leaves.push_back(i);
            degree[i] = 0;
        }
    }

    int processed = leaves.size();

    // Remove leaf nodes and decrease the degree of each node adding new leaf nodes progressively
    // until only the centers remain.
    while (processed < n) {
        vector <int> newLeaves;
        for (int node : leaves) {
            for (int neighbour : tree[node]) {
                if (--degree[neighbour] == 1) {
                    newLeaves.push_back(neighbour);
                } 
            }
            degree[node] = 0;
        }
        processed += newLeaves.size();
        leaves = newLeaves;
    }
    return leaves;
}

void addUndirectedEdge(vector <vector <int>> &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

int main() {
    // Testing 
    vector <vector <int>> graph(9);
    addUndirectedEdge(graph, 0, 1);
    addUndirectedEdge(graph, 2, 1);
    addUndirectedEdge(graph, 2, 3);
    addUndirectedEdge(graph, 3, 4);
    addUndirectedEdge(graph, 5, 3);
    addUndirectedEdge(graph, 2, 6);
    addUndirectedEdge(graph, 6, 7);
    addUndirectedEdge(graph, 6, 8);
    // Center should be 2.
    printf ("Tree center(s) are : %d\n", findCenters(graph)[0]);
    return 0;
}