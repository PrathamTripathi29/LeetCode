class Solution {
    public int fib(int n) {
        if(n < 2){
            return n;
        }
        int[] memo = new int[n+1];
        Arrays.fill(memo, -1);
        if(memo[n] == -1){
            return memo[n] = fib(n-1) + fib(n-2);
        }
        return memo[n];
    }
}
