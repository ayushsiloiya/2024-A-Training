import java.util.Arrays;

public class Algorithms {
    // 0-1 Knapsack
    public static int knapsack(int[] weights, int[] values, int capacity) {
        int n = weights.length;
        int[][] dp = new int[n + 1][capacity + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= capacity; j++) {
                if (weights[i - 1] <= j) {
                    dp[i][j] = Math.max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][capacity];
    }

    // Longest Common Subsequence (LCS)
    public static int lcs(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        int[][] dp = new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    // Matrix Chain Multiplication (MCM)
    public static int mcm(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];

        for (int len = 2; len < n; len++) {
            for (int i = 1; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = Math.min(dp[i][j], cost);
                }
            }
        }

        return dp[1][n - 1];
    }

    // Unbounded Knapsack
    public static int unboundedKnapsack(int[] weights, int[] values, int capacity) {
        int n = weights.length;
        int[] dp = new int[capacity + 1];

        for (int i = 1; i <= capacity; i++) {
            for (int j = 0; j < n; j++) {
                if (weights[j] <= i) {
                    dp[i] = Math.max(dp[i], dp[i - weights[j]] + values[j]);
                }
            }
        }

        return dp[capacity];
    }

    // Longest Increasing Subsequence (LIS)
    public static int lis(int[] arr) {
        int n = arr.length;
        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] > arr[j]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxLIS = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] > maxLIS) {
                maxLIS = dp[i];
            }
        }

        return maxLIS;
    }

    public static void main(String[] args) {
        // 0-1 Knapsack
        int[] weights = { 1, 2, 3 };
        int[] values = { 6, 10, 12 };
        int capacity = 5;

        int maxValue = knapsack(weights, values, capacity);
        System.out.println("Maximum value in knapsack: " + maxValue);

        // Longest Common Subsequence (LCS)
        String s1 = "ABCD";
        String s2 = "ACDF";

        int lcsLength = lcs(s1, s2);
        System.out.println("Length of Longest Common Subsequence: " + lcsLength);

        // Matrix Chain Multiplication (MCM)
        int[] arr = { 10, 30, 5, 60 };
        int minCost = mcm(arr);
        System.out.println("Minimum cost of matrix chain multiplication: " + minCost);

        // Unbounded Knapsack
        int[] w = { 2, 3, 4, 5 };
        int[] v = { 3, 4, 5, 6 };
        int cap = 5;

        int maxVal = unboundedKnapsack(w, v, cap);
        System.out.println("Maximum value in unbounded knapsack: " + maxVal);

        // Longest Increasing Subsequence (LIS)
        int[] lisArr = { 10, 22, 9, 33, 21, 50, 41, 60 };
        int maxLIS = lis(lisArr);
        System.out.println("Length of Longest Increasing Subsequence: " + maxLIS);
    }
}
