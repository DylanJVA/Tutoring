public class Fibonacci {
    public static void main(String[] args) {
        System.out.println("Fibonacci(9) = "+fib(9));
        int[] myArray = {54, 12, 8, 91};
        System.out.println("Recursive sum = "+recursiveSum(myArray));
    }

    public static fib(int N) {
        if (N <= 1)
            return;
        return fib(N-1)+fib(N-2);
    }
