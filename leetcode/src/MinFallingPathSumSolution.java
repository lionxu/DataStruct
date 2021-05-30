public class MinFallingPathSumSolution {
    public static void main(String[] args) {
        MinFallingPathSumSolution solution = new MinFallingPathSumSolution();
        int[][] matrix = {
                {2, 1, 3},
                {6, 5, 4},
                {7, 8, 9}
        };

        System.out.println(solution.minFallingPathSum(matrix));
    }

    public int minFallingPathSum(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] memo = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = Integer.MAX_VALUE;
            }
        }

        int result = Integer.MAX_VALUE;

        // 最小值可能出现在最后一行的任意一列
        for (int i = 0; i < n; i++) {
            result = Math.min(dp(matrix, m - 1, i, memo), result);
        }

        return result;
    }

    private int dp(int[][] matrix, int i, int j, int[][] memo) {
        int m = matrix.length;
        int n = matrix[0].length;

        // 边界异常情况检查
        if (i < 0 || i >= m || j < 0 || j >= n) return Integer.MAX_VALUE;

        // base case处理
        if (i == 0) {
            return matrix[i][j];
        }

        if (memo[i][j] != Integer.MAX_VALUE) {
            return memo[i][j];
        }

        // 应该是先求出子问题的最小值后,再加上当前的值
        memo[i][j] = matrix[i][j] + minThree(
                dp(matrix, i - 1, j, memo),
                dp(matrix, i - 1, j - 1, memo),
                dp(matrix, i - 1, j + 1, memo)
        );

        return memo[i][j];
    }

    private int minThree(int a, int b, int c) {
        return Math.min(Math.min(a, b), c);
    }
}
