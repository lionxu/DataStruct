import java.util.HashMap;
import java.util.Map;

public class FindTargetSumWaysSolution {

    public static void main(String[] args) {
        FindTargetSumWaysSolution solution = new FindTargetSumWaysSolution();
        int[] nums = {1, 1, 1, 1, 1};
        int target = 3;
        System.out.println(solution.findTargetSumWays(nums, target));
    }

    public int findTargetSumWays(int[] nums, int target) {

        if (nums.length == 0) return 0;

        Map<String, Integer> memo = new HashMap<>(1);

        return dp(nums, 0, target, memo);
    }

    public int findTargetSumWaysV2(int[] nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (target > sum || (target + sum) % 2 == 1){
            return 0;
        }

        return subsets(nums, (target + sum) / 2);
    }

    /**
     * 动态规划
     */
    private int dp(int[] nums, int i, int rest, Map<String, Integer> memo) {

        int n = nums.length;

        // 边界情况处理
        if (i == n) {
            if (rest == 0) return 1;
            else return 0;
        }

        // 创建重叠子问题的key
        String historyKey = i + "," + rest;
        if (memo.containsKey(historyKey)) {
            return memo.get(historyKey);
        }

        // 穷举迭代子问题
        int result = dp(nums, i + 1, rest - nums[i], memo) + dp(nums, i + 1, rest + nums[i], memo);

        memo.put(historyKey, result);

        return result;
    }

    /**
     * 运用背包算法求解
     */
    private int subsets(int[] nums, int sum) {
        int n = nums.length;

        int[][] dp = new int[n + 1][sum + 1];

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
}
