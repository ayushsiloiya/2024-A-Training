import java.util.Arrays;

public class UnboundedKnapsack {
    public static int unboundedKnapsack(int[] values, int[] weights, int capacity) {
        int n = values.length;
        int[][] dp = new int[n + 1][capacity + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        return knapsackHelper(values, weights, n, capacity, dp);
    }

    public static int knapsackHelper(int[] values, int[] weights, int n, int capacity, int[][] dp) {
        if (n == 0 || capacity == 0) {
            return 0;
        }

        if (dp[n][capacity] != -1) {
            return dp[n][capacity];
        }

        if (weights[n - 1] <= capacity) {
            dp[n][capacity] = Math.max(
                values[n - 1] + knapsackHelper(values, weights, n, capacity - weights[n - 1], dp),
                knapsackHelper(values, weights, n - 1, capacity, dp)
            );
        } else {
            dp[n][capacity] = knapsackHelper(values, weights, n - 1, capacity, dp);
        }

        return dp[n][capacity];
    }

    public static void main(String[] args) {
        int[] values = { 10, 40, 50, 70 };
        int[] weights = { 1, 3, 4, 5 };
        int capacity = 8;

        int maxValue = unboundedKnapsack(values, weights, capacity);
        System.out.println("Maximum value in the knapsack: " + maxValue);
    }
}
