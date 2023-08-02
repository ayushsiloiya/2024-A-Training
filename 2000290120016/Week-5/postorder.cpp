/*
    Code of Post-order Traversal of Binary Tree
    
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

void postorder(BTNode *root) {
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << endl;
}

int main() {
    vector<int> a = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    cout << "Array 'a' : ";
    for(int i : a) cout << i << " ";
    cout << endl << endl;

    BinaryTree bin(a);

    cout << "Postorder Traversal of 'a' :" << endl;
    postorder(bin.getRoot());

    return 0;
}