/**
 * Sometimes it’s useful to root an undirected
 * tree to add structure to the problem you’re
 * trying to solve. Rooting a tree can be easily
 * done using depth first search.  
 *
 * Author : Yatharth Goswami
 * Github ID : yatharth0610
 * Email : yatharthgoswami15@gmail.com
 *
 */

#include <bits/stdc++.h>

using namespace std;

class Node {
    public : 
        int id;
        Node* parent;
        vector <Node*> children;

        Node(int x) {
            id = x;
            parent = NULL;
        } 

        Node (int x, Node* node) {
            id = x;
            parent = node;
        }

        void addChildren(vector <Node*> v) {
            for (Node* node : v) {
                children.push_back(node);
            }
        }   
};

// Dfs to construct the rooted tree.
Node* buildTree(vector <vector<int>> graph, Node* node) {
    for (int childId : graph[(*node).id]) {
        if ((*node).parent != NULL && childId == (*(*node).parent).id) {
            continue;
        }
        Node* child = new Node(childId, node);
        (*node).addChildren({child});
        buildTree(graph, child);
    }
    return node;
}

Node* rootTree(vector <vector<int>> graph, int id) {
    Node* root = new Node(id);
    return buildTree(graph, root);
}

void addUndirectedEdge(vector <vector <int>> &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

int main() {
    // Testing the program.
    vector <vector <int>> graph(9);
    addUndirectedEdge(graph, 2, 1);
    addUndirectedEdge(graph, 2, 3);
    addUndirectedEdge(graph, 2, 6);
    addUndirectedEdge(graph, 6, 7);
    addUndirectedEdge(graph, 6, 8);
    // Tree rooted at 6 should look like this
    //           6
    //      2    7     8
    //    1   3
    Node* root = rootTree(graph, 6);
    
    cout << (*root).id << endl;
    for (Node* node: (*root).children) {
        cout << (*node).id << " ";
    }
    cout << '\n';
    for (Node* node : ((*((*root).children[0])).children)) {
        cout << (*node).id << " ";
    }
    return 0;
}