/**
 * The basic idea to be used while implementing this is to 
 * traverse the tree starting from a node and then if the 
 * node is a leaf, then add the value to a global variable
 * 
 * Author : Yatharth Goswami
 * Github ID : yatharth0610
 * Email : yatharthgoswami15@gmail.com
 * 
 */


#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int value;
        vector <Node *> children;

        Node (int x) {
            value = x;
        }

        int getValue() {
            return value;
        }

        vector <Node*> getChildren() {
            return children;
        }

        void addChild(vector <Node*> v) {
            for (Node* n : v) {
                children.push_back(n);
            }
        }
};

int leafSum(Node* node) {
    // To handle the case of empty tree.
    if (node == NULL) {
        return 0;
    }
    int total = 0;
    Node cur = *node;
    if ((cur.getChildren()).size() == 0) {
        return cur.getValue();
    }
    for (Node* child : cur.getChildren()) {
         total += leafSum(child);
    }
    return total;
}

int main() {
    Node* root = new Node(5);

    Node* node4 = new Node(4);
    Node* node3 = new Node(3);
    (*root).addChild({node4, node3});

    Node* node1 = new Node(1);
    Node* nodem6 = new Node(-6);
    (*node4).addChild({node1, nodem6});

    Node* node0 = new Node(0);
    Node* node7 = new Node(7);
    Node* nodem4 = new Node(-4);
    (*node3).addChild({node0, node7, nodem4});

    Node* node2 = new Node(2);
    Node* node9 = new Node(9);
    (*node1).addChild({node2, node9});

    Node* node8 = new Node(8);
    (*node7).addChild({node8});

    printf ("Leaf sum : %d\n", leafSum(root));
    return 0;
}