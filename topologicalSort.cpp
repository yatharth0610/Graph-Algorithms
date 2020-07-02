/**
 * A topological ordering is a linear ordering of its vertices such 
 * that for every directed edge uv from vertex u to v, u comes before
 * v in the ordering. A good way to get this ordering is to use dfs on
 * the graph and add node in the array during the callback.
 *
 * Author : Yatharth Goswami
 * Github ID : yatharth0610
 * Email : yatharthgoswami15@gmail.com
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Edge {
    public : 
        int from, to, weight;

        Edge(int a, int b, int w) {
            from = a;
            to = b;
            weight = w;
        }
};

// Instead of maintaining a stack of the nodes we see we simply place 
// them inside the ordering array in reverse order for simplicity.

int dfs(int i, int cur, vector <bool> &visited, vector <int> &ordering, map<int, vector<Edge> > graph) {
    visited[cur] = true;
    vector <Edge> edges = graph[cur];

    if (edges.size() != 0) {
        for (Edge e : edges) {
            if (!visited[e.to]) {
                i = dfs(i, e.to, visited, ordering, graph);
            }
        }
    }

    ordering[i] = cur;
    return i-1;
}

vector <int> topSort(map<int, vector <Edge> > graph, int numNodes) {
    vector <int> ordering(numNodes);
    vector <bool> visited(numNodes, false);
    int i = numNodes-1;

    for (int cur = 0; cur < numNodes; cur++) {
        if (!visited[cur]) i = dfs(i, cur, visited, ordering, graph);
    }

    return ordering;
}

int main() {
    // Testing the code.
    int n = 7;
    map <int, vector <Edge> > graph;
    graph[0].push_back(*(new Edge(0,1,3)));
    graph[0].push_back(*(new Edge(0,2,2)));
    graph[0].push_back(*(new Edge(0,5,3)));
    graph[1].push_back(*(new Edge(1,3,1)));
    graph[1].push_back(*(new Edge(1,2,6)));
    graph[2].push_back(*(new Edge(2,3,1)));
    graph[2].push_back(*(new Edge(2,4,10)));
    graph[3].push_back(*(new Edge(3,4,5)));
    graph[5].push_back(*(new Edge(5,4,7)));
    
    vector <int> ordering = topSort(graph, n);
    cout << "The topological ordering is: " << endl;
    for (int x : ordering) cout << x << ' ';
    return 0;
}