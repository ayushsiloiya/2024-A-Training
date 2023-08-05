import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class TreeTraversalAndSearch {
    // Validate BST
    public static boolean isValidBST(TreeNode root) {
        return isValidBSTHelper(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    private static boolean isValidBSTHelper(TreeNode root, long minVal, long maxVal) {
        if (root == null) {
            return true;
        }
        if (root.val <= minVal || root.val >= maxVal) {
            return false;
        }
        return isValidBSTHelper(root.left, minVal, root.val) && isValidBSTHelper(root.right, root.val, maxVal);
    }

    // Postorder Traversal
    public static void postorder(TreeNode root) {
        if (root == null) {
            return;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.val + " ");
    }

    // Preorder Traversal
    public static void preorder(TreeNode root) {
        if (root == null) {
            return;
        }
        System.out.print(root.val + " ");
        preorder(root.left);
        preorder(root.right);
    }

    // Depth-First Search (DFS)
    public static void dfs(TreeNode root) {
        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            System.out.print(node.val + " ");

            if (node.right != null) {
                stack.push(node.right);
            }
            if (node.left != null) {
                stack.push(node.left);
            }
        }
    }

    // Breadth-First Search (BFS)
    public static void bfs(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            System.out.print(node.val + " ");

            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
    }

    // Inorder Traversal
    public static void inorder(TreeNode root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    // Level Order Traversal
    public static void levelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode node = queue.poll();
                System.out.print(node.val + " ");

                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(8);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(9);

        // Validate BST
        boolean isValid = isValidBST(root);
        System.out.println("Is the given tree a valid BST? " + isValid);

        // Postorder Traversal
        System.out.print("Postorder Traversal: ");
        postorder(root);
        System.out.println();

        // Preorder Traversal
        System.out.print("Preorder Traversal: ");
        preorder(root);
        System.out.println();

        // Depth-First Search (DFS)
        System.out.print("DFS: ");
        dfs(root);
        System.out.println();

        // Breadth-First Search (BFS)
        System.out.print("BFS: ");
        bfs(root);
        System.out.println();

        // Inorder Traversal
        System.out.print("Inorder Traversal: ");
        inorder(root);
        System.out.println();

        // Level Order Traversal
        System.out.print("Level Order Traversal: ");
        levelOrder(root);
        System.out.println();
    }
}
