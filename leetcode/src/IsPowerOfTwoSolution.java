/**
 * 231: 2的幂
 */
public class IsPowerOfTwoSolution {
    public static void main(String[] args) {
        System.out.println(isPowerOfTwo(1));
    }

    public static boolean isPowerOfTwo(int n){
        if (n <= 0) return false;

        // 此处需要注意&与==的优先级问题
        // &的优先级比==的优先级低
        // 所以需要加括号
        return (n & (n - 1)) == 0;
    }
}
