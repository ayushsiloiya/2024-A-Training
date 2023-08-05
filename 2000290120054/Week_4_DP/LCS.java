import java.util.Arrays;

public class LCS {

    public static int longestCommonSubsequence(String text1, String text2) {
        int[][] memo = new int[text1.length() + 1][text2.length() + 1];
        for (int[] row : memo) {
            Arrays.fill(row, -1);
        }
        return lcsHelper(text1, text2, text1.length(), text2.length(), memo);
    }

    private static int lcsHelper(String text1, String text2, int m, int n, int[][] memo) {
        if (m == 0 || n == 0) {
            return 0;
        }

        if (memo[m][n] != -1) {
            return memo[m][n];
        }

        if (text1.charAt(m - 1) == text2.charAt(n - 1)) {
            memo[m][n] = 1 + lcsHelper(text1, text2, m - 1, n - 1, memo);
        } else {
            memo[m][n] = Math.max(lcsHelper(text1, text2, m - 1, n, memo), lcsHelper(text1, text2, m, n - 1, memo));
        }

        return memo[m][n];
    }

    public static void main(String[] args) {
        String text1 = "abcde";
        String text2 = "ace";

        int result = longestCommonSubsequence(text1, text2);
        System.out.println("Longest Common Subsequence length: " + result);
    }
}
