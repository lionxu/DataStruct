import java.util.Arrays;

public class LengthOfLISSolution {
    public static void main(String[] args) {
        LengthOfLISSolution solution = new LengthOfLISSolution();
        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};

        System.out.println(solution.lengthOfLIS(nums));
    }

    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] memo = new int[n];

        // base case
        Arrays.fill(memo, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // 状态转移方程
                if (nums[i] > nums[j]) {
                    memo[i] = Math.max(memo[i], 1 + memo[j]);
                }
            }
        }

        int result = 0;

        // 寻找最长子序列
        for (int i = 0; i < n; i++) {
            result = Math.max(result, memo[i]);
        }

        return result;
    }
}
