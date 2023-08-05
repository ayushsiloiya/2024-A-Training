import java.util.Arrays;

public class LIS {
    public static int lis(int[] nums) {
        int n = nums.length;
        int[] memo = new int[n];
        Arrays.fill(memo, -1);
        int maxLIS = 0;

        for (int i = 0; i < n; i++) {
            maxLIS = Math.max(maxLIS, lisRecursive(nums, i, memo));
        }

        return maxLIS;
    }

    private static int lisRecursive(int[] nums, int currentIndex, int[] memo) {
        if (memo[currentIndex] != -1) {
            return memo[currentIndex];
        }

        int currentNumber = nums[currentIndex];
        int maxLength = 1;

        for (int i = currentIndex + 1; i < nums.length; i++) {
            if (nums[i] > currentNumber) {
                int subsequenceLength = 1 + lisRecursive(nums, i, memo);
                maxLength = Math.max(maxLength, subsequenceLength);
            }
        }

        memo[currentIndex] = maxLength;
        return maxLength;
    }

    public static void main(String[] args) {
        int[] nums = { 10, 22, 9, 33, 21, 50, 41, 60 };
        int result = lis(nums);
        System.out.println("Longest Increasing Subsequence length: " + result);
    }
}
