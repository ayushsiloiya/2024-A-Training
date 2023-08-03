/*
    Code of Level-order Traversal of Binary Tree
    
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

void levelorder(BTNode *root) {
    if(!root) {
        cout << "UNDERFLOW : Tree is Empty" << endl;
        return;
    }

    queue<BTNode*> lvl;
    lvl.push(root);

    while(!lvl.empty()) {
        BTNode *node = lvl.front();
        lvl.pop();

        cout << node->val << endl;

        if(node->left) lvl.push(node->left);
        if(node->right) lvl.push(node->right);
    }
}

int main() {
    vector<int> a = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    cout << "Array 'a' : ";
    for(int i : a) cout << i << " ";
    cout << endl << endl;

    BinaryTree bin(a);

    cout << "Inorder Traversal of 'a' :" << endl;
    levelorder(bin.getRoot());

    return 0;
}