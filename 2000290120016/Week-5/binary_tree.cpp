/*
    Library for Binary Tree

    Created by
        Ajay Varshney
        2000290120016
        CS 6A
*/

struct BTNode {
    int val;
    BTNode *left;
    BTNode *right;

    BTNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    BTNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    BTNode(int x, BTNode *l, BTNode *r) {
        val = x;
        left = l;
        right = r;
    }
};

void inorderPrint(BTNode *root) {
    if(!root) {return;}

    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

void preorderPrint(BTNode *root) {
    if(!root) return;

    cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}

void postorderPrint(BTNode *root) {
    if(!root) return;

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->val << " ";
}

void levelorderPrint(BTNode *root) {
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

class BinaryTree {
    BTNode *root;
    queue<BTNode*> nodesWithNULLChild;
public:
    BinaryTree() {
        root = nullptr;
    }

    BinaryTree(vector<int> &a) {
        // constructor for converting a array into binary tree
        // this assumes that array is level order traversal of resulting binary tree
        // [1 2 3 4]
        //     1     ---->
        //    / \
        //   2   3     ---->
        //  /
        // 4     ---->
        // [1 2 3 4 5]
        //     1     ---->
        //    / \
        //   2   3     ---->
        //  / \
        // 4   5     ---->

        root = new BTNode(a[0]);
        
        int i = 1;
        nodesWithNULLChild.push(root);

        while(!nodesWithNULLChild.empty() && i < a.size()) {
            BTNode *node = nodesWithNULLChild.front();

            if(i < a.size() && !node->left) {
                node->left = new BTNode(a[i]);
                nodesWithNULLChild.push(node->left);
                ++i;
            }
            if(i < a.size() && !node->right) {
                node->right = new BTNode(a[i]);
                nodesWithNULLChild.push(node->right);
                ++i;
            }
            
            if(node->left && node->right)
                nodesWithNULLChild.pop();
        }
    }

    BTNode* getRoot() { return root; }

    void insert(int val) {
        BTNode *node = new BTNode(val);
        nodesWithNULLChild.push(node);
        
        BTNode *firstNullChildNode = nodesWithNULLChild.front();

        if(root) {
            if(!firstNullChildNode->left) firstNullChildNode->left = node;
            else if(!firstNullChildNode->right) firstNullChildNode->right = node;
        }
        else root = node;

        if(firstNullChildNode->left && firstNullChildNode->right) nodesWithNULLChild.pop();
        cout << "Q Size : " << nodesWithNULLChild.size() << endl;
    }

    void insert(vector<int> &a) {
        if(a.size() == 0) {
            cout << "UNDERFLOW (Array) : Array is empty" << endl;
            return;
        }

        for(int i : a) insert(i);
    }

    void preorder() {
        if(!root) {
            cout << "UNDERFLOW : Tree is Empty" << endl;
            return;
        }
        preorderPrint(root);
    }

    void inorder() {
        if(!root) {
            cout << "UNDERFLOW : Tree is Empty" << endl;
            return;
        }
        inorderPrint(root);
    }

    void postorder() {
        if(!root) {
            cout << "UNDERFLOW : Tree is Empty" << endl;
            return;
        }
        postorderPrint(root);
    }

    void levelorder() {
        levelorderPrint(root);
    }
};