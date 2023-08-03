/*
    Code of Breadth First Search (BFS)
    
    By 
    Ajay Varshney
    2000290120016
    CS 6A

*/

#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

#include "binary_tree.cpp"

void bfs(BTNode *root) {
    if(!root) {
        cout << "UNDERFLOW : Tree is Empty" << endl;
        return;
    }

    queue<BTNode*> lvl;
    lvl.push(root);

    while(!lvl.empty()) {
        BTNode *node = lvl.front();
        lvl.pop();

        cout << node->val << " ";

        if(node->left) lvl.push(node->left);
        if(node->right) lvl.push(node->right);
    }
}

int main() {
    vector<int> a = {50, 25, 75, 10, 30, 60, 100};
    cout << "Array 'a' : ";
    for(int i : a) cout << i << " ";
    cout << endl << endl;

    BinaryTree t(a);

    cout << "BFS Traversal of 'a' :" << endl;
    bfs(t.getRoot());
    
    return 0;
}