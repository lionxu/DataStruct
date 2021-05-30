import java.util.HashMap;
import java.util.Map;

public class MinDistanceSolution {
    public static void main(String[] args) {
        MinDistanceSolution solution = new MinDistanceSolution();
        String word1 = "intention";
        String word2 = "execution";
        System.out.println(solution.minDistance(word1, word2));
    }

    public int minDistance(String word1, String word2) {
        Map<String, Integer> memo = new HashMap<>(1);
        return dp(word1, word2, word1.length() - 1, word2.length() - 1, memo);
    }

    public int minDistanceV2(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();

        int[][] dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int j = 1; j <= m; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + minThree(
                            dp[i - 1][j - 1],
                            dp[i - 1][j],
                            dp[i][j - 1]
                    );
                }
            }
        }

        return dp[n][m];

    }

    /**
     * 动态规划
     *
     * @param word1
     * @param word2
     * @param i     word1的索引
     * @param j     word2的索引
     * @return 操作次数
     */
    private int dp(String word1, String word2, int i, int j, Map<String, Integer> memo) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;

        String historyKey = i + "," + j;

        if (memo.containsKey(historyKey)) {
            return memo.get(historyKey);
        }

        if (word1.charAt(i) == word2.charAt(j)) {
            memo.put(historyKey, dp(word1, word2, i - 1, j - 1, memo));
        } else {
            memo.put(historyKey, 1 + minThree(
                    // 替换操作
                    dp(word1, word2, i - 1, j - 1, memo),
                    // 删除操作
                    dp(word1, word2, i - 1, j, memo),
                    // 插入操作
                    dp(word1, word2, i, j - 1, memo)
            ));
        }

        return memo.get(historyKey);
    }

    private int minThree(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }
}
