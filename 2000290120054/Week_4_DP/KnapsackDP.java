import java.util.Arrays;

public class KnapsackDP {

    static int knapsack(int[] values, int[] weights, int W) {
        int n = values.length;
        int[][] memo = new int[n + 1][W + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return knapsackHelper(values, weights, n, W, memo);
    }

    private static int knapsackHelper(int[] values, int[] weights, int n, int W, int[][] memo) {
        if (n == 0 || W == 0) {
            return 0;
        }

        if (memo[n][W] != -1) {
            return memo[n][W];
        }

        if (weights[n - 1] > W) {
            memo[n][W] = knapsackHelper(values, weights, n - 1, W, memo);
            return memo[n][W];
        }

        int included = values[n - 1] + knapsackHelper(values, weights, n - 1, W - weights[n - 1], memo);
        int excluded = knapsackHelper(values, weights, n - 1, W, memo);
        memo[n][W] = Math.max(included, excluded);
        return memo[n][W];
    }

    public static void main(String[] args) {
        int[] values = {60, 100, 120};
        int[] weights = {10, 20, 30};
        int W = 50;

        int maxValue = knapsack(values, weights, W);
        System.out.println("Maximum value that can be obtained: " + maxValue);
    }
}
