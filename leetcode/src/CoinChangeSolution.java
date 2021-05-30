import java.util.HashMap;
import java.util.Map;

public class CoinChangeSolution {
    public static void main(String[] args) {
        CoinChangeSolution solution = new CoinChangeSolution();
        int[] coins = {1, 2, 5};
        int amount = 11;
        System.out.println(solution.coinChange(coins, amount));
    }

    public int coinChange(int[] coins, int amount) {
        Map<Integer, Integer> memo = new HashMap<>(1);
        return dp(coins, amount, memo);
    }

    private int dp(int[] coins, int amount, Map<Integer, Integer> memo) {
        // 边界情况的处理
        if (amount == 0) return 0;
        if (amount < 0) return -1;

        if (memo.containsKey(amount)) {
            return memo.get(amount);
        }

        int result = Integer.MAX_VALUE;
        // 子问题的结果
        int subResult = 0;
        for (int coin : coins) {
            subResult = dp(coins, amount - coin, memo);

            // 说明子问题无法对换
            if (subResult == -1) {
                continue;
            }

            // 对结果进行累加
            result = Math.min(result, 1 + subResult);
        }

        if (result == Integer.MAX_VALUE) {
            memo.put(amount, -1);
        }else {
            memo.put(amount, result);
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }
}
