/**
 * Notion of Graph isomorphism can be defined rigorously as  
 * G1 (V1 , E1) and G2 (V2 , E2) are isomorphic if
 * there exists a bijection φ between the sets
 * V1 -> V2 such that:
 * ∀ u,v ∈ V1 , (u,v) ∈ E1 ⟺ (φ(u),φ(v)) ∈ E2
 * 
 * The isomorphism for trees can be easily verified by encoding 
 * both the trees using the AHU algorithm by first rooting them
 * at the centres and then checking for the equality of this 
 * encoded string.
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

// Constructs the encoded form of the trees as a string.
string encode(Node* node) {
    if (node == NULL) {
        return "";
    }
    vector <string> labels;
    for (Node* child : (*node).children) {
        labels.push_back(encode(child));
    }
    sort (labels.begin(), labels.end());

    string ans;
    for (string s : labels) ans += s;
    return "(" + ans + ")";
}

// Determines if two unrooted trees are isomorphic.
bool checkIsomorphism (vector <vector <int>> tree1, vector <vector <int>> tree2) {
    vector <int> centers1 = findCenters(tree1);
    vector <int> centers2 = findCenters(tree2);

    Node* root = rootTree(tree1, centers1[0]);
    string tree1_encoding = encode(root);

    for (int center : centers2) {
        Node* root2 = rootTree(tree2, center);
        string tree2_encoding = encode(root2);

        if (tree1_encoding == tree2_encoding) return true;
    }
    return false;
}

void addUndirectedEdge(vector <vector <int>> &graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

int main() {
    // Testing the program
    vector <vector <int>> tree1(5), tree2(5);
    addUndirectedEdge(tree1, 2, 0);
    addUndirectedEdge(tree1, 3, 4);
    addUndirectedEdge(tree1, 2, 1);
    addUndirectedEdge(tree1, 2, 3);

    addUndirectedEdge(tree2, 1, 0);
    addUndirectedEdge(tree2, 2, 4);
    addUndirectedEdge(tree2, 1, 3);
    addUndirectedEdge(tree2, 1, 2);

    if (!checkIsomorphism(tree1, tree2)) {
        cout << "Oops! These trees should have been isomorphic";
    }
    else cout << "Yippee! The program gave correct result!";
}