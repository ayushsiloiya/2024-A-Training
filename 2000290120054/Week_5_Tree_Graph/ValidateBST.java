 class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class ValidateBST {
    public boolean isValidBST(TreeNode root) {
        return isValidBSTHelper(root, null, null);
    }

    private boolean isValidBSTHelper(TreeNode node, Integer min, Integer max) {
        if (node == null) {
            return true;
        }

        if ((min != null && node.val <= min) || (max != null && node.val >= max)) {
            return false;
        }

        return isValidBSTHelper(node.left, min, node.val) && isValidBSTHelper(node.right, node.val, max);
    }

    public static void main(String[] args) {
        ValidateBST validator = new ValidateBST();
        TreeNode root1 = new TreeNode(5);
        root1.left = new TreeNode(3);
        root1.right = new TreeNode(8);
        root1.left.left = new TreeNode(2);
        root1.left.right = new TreeNode(4);
        root1.right.left = new TreeNode(6);
        root1.right.right = new TreeNode(9);
        System.out.println("Is Valid BST 1: " + validator.isValidBST(root1)); 
        TreeNode root2 = new TreeNode(5);
        root2.left = new TreeNode(3);
        root2.right = new TreeNode(8);
        root2.left.left = new TreeNode(2);
        root2.left.right = new TreeNode(6); 
        root2.right.left = new TreeNode(6);
        root2.right.right = new TreeNode(9);
        System.out.println("Is Valid BST 2: " + validator.isValidBST(root2)); 
    }
}
