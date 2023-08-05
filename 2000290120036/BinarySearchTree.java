public class BinarySearchTree {

    public class Node {
        public int data;
        public Node left;
        public Node right;
        public Node(int data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }

    }
    public Node root;
    public BinarySearchTree() {
        this.root = null;
    }
    public void insert(int newData) {
        this.root = insert(root, newData);
    }

    public Node insert(Node root, int newData) {

        if (root == null) {
           
            root = new Node(newData);
          
            return root;
        }
  
        else if (root.data >= newData) {
          
            root.left = insert(root.left, newData);
        } else {
     
            root.right = insert(root.right, newData);
        }
        return root;
    }


    public void preorder() {
        preorder(root);
    }

    public void preorder(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);

    }
    public static void main(String[] args) {

        BinarySearchTree bst = new BinarySearchTree();
      
        bst.insert(2);
        bst.insert(4);
        bst.insert(1);
        bst.insert(3);
        bst.insert(5);
        bst.preorder();
    }
    
}