/**
 * The basic idea to be used while implementing this is to 
 * recursively find the height of the subtrees and add 1 to 
 * the maximum height of left or right subtree to get the height
 * of the tree rooted at the current node. A smart way to implem-
 * -ent the program is to return -1 if the tree is empty.
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
        int value;
        Node* l;
        Node* r;

        Node (int x) {
            value = x;
        }

        Node getValue() {
            return value;
        }
};

// Returns the height of the binary tree which is the number of edges from the
// root to the deepest leaf node, or -1 if the input is an empty tree.
int treeHeight (Node* node) {
    // Handles the case of empty tree.
    if (node == NULL) return -1;
    return max(treeHeight((*node).l), treeHeight((*node).r)) + 1;
}

int main() {
    // Testing the program.
    printf ("Empty tree : %d\n", treeHeight(NULL));
    printf ("Singleton Height : %d\n", treeHeight(new Node(0)));
    Node* root = new Node(0);
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    (*root).l = node1;
    (*root).r = node2;

    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    (*node1).l = node3;
    (*node1).r = node4;
    
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);
    (*node2).l = node5;
    (*node2).r = node6;
    
    Node* node7 = new Node(7);
    Node* node8 = new Node(8);
    (*node3).l = node7;
    (*node3).r = node8;
    printf ("Tree Height : %d\n", treeHeight(root));
    return 0;
}