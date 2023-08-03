/*
    Code of Validate BST
    
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

bool isBST(BTNode *root) {
    if(!root) return true;

    if(root->left && root->val < root->left->val) return false;
    if(root->right && root->val >= root->right->val) return false;

    return isBST(root->left) && isBST(root->right);
}

int main() {
    vector<int> a1 = {50, 25, 75, 10, 30, 60, 100};
    cout << "Tree t1 made with Array 'a1' : ";
    for(int i : a1) cout << i << " ";
    cout << endl;

    BinaryTree t1(a1);
    cout << "is Binary Tree 't1' is BST : " << (isBST(t1.getRoot()) ? "YES" : "NO") << endl << endl;
    
    vector<int> a2 = {50, 25, 75, 10, 30, 60, 1};
    cout << "Tree t1 made with Array 'a2' : ";
    for(int i : a2) cout << i << " ";
    cout << endl;

    BinaryTree t2(a2);
    cout << "is Binary Tree 't2' is BST : " << (isBST(t2.getRoot()) ? "YES" : "NO") << endl << endl;

    return 0;
}