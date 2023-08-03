/*
    Code of Depth First Search (DFS)
    
    By 
    Ajay Varshney
    2000290120016
    CS 6A

*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::queue;
using std::stack;

#include "binary_tree.cpp"

void dfs(BTNode *root) {
    if(!root) {
        cout << "UNDERFLOW : Tree is Empty" << endl;
        return;
    }

    stack<BTNode*> depth;
    depth.push(root);

    while(!depth.empty()) {
        BTNode *node = depth.top();
        depth.pop();

        cout << node->val << " ";

        if(node->left) depth.push(node->left);
        if(node->right) depth.push(node->right);
    }
}

int main() {
    vector<int> a = {50, 25, 75, 10, 30, 60, 100};
    cout << "Array 'a' : ";
    for(int i : a) cout << i << " ";
    cout << endl << endl;

    BinaryTree t(a);

    cout << "DFS Traversal of 'a' :" << endl;
    dfs(t.getRoot());

    return 0;
}