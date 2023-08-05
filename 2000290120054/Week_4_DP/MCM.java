public class MCM {
    public static int matrixChainOrder(int[] dimensions) {
        int n = dimensions.length;
        int[][] memo = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1; 
            }
        }
        return matrixChainOrderRecursive(dimensions, 1, n - 1, memo);
    }

    private static int matrixChainOrderRecursive(int[] dimensions, int i, int j, int[][] memo) {
        if (i == j) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        int minCost = Integer.MAX_VALUE;
        for (int k = i; k < j; k++) {
            int cost = matrixChainOrderRecursive(dimensions, i, k, memo)
                    + matrixChainOrderRecursive(dimensions, k + 1, j, memo)
                    + dimensions[i - 1] * dimensions[k] * dimensions[j];
            minCost = Math.min(minCost, cost);
        }

        memo[i][j] = minCost;
        return minCost;
    }

    public static void main(String[] args) {
        int[] dimensions = {10, 30, 5, 60};
        int minCost = matrixChainOrder(dimensions);
        System.out.println("Minimum cost of matrix chain multiplication: " + minCost);
    }
}
