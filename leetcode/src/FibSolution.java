import java.util.HashMap;
import java.util.Map;

/**
 * 509 斐波那契数列
 */
public class FibSolution {
    public static void main(String[] args) {
        FibSolution fibSolution = new FibSolution();

        System.out.println(fibSolution.fib(1));
    }

    public int fib(int n) {
        Map<Integer, Integer> memo = new HashMap<>(1);

        return dp(n, memo);
    }

    /**
     * 使用动态规划
     * @param n 目标
     * @param memo 使用历史记录,消除重叠子问题
     * @return 计算结果
     */
    private int dp(int n, Map<Integer, Integer> memo) {
        if (n == 0) return 0;

        if (n == 1 || n == 2) return 1;

        if (memo.containsKey(n)){
            return memo.get(n);
        }

        int result = dp(n - 1, memo) + dp(n - 2, memo);

        memo.put(n, result);

        return result;
    }
}
