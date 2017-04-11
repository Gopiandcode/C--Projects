import java.math.*;
import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
            int test_cases;
            Scanner sc = new Scanner(System.in);
            test_cases = sc.nextInt();

            for(int p = 0; p<test_cases; p++) {
                int A, B, C;
                A = sc.nextInt();
                B = sc.nextInt();
                C = sc.nextInt();

                BigInteger arr[][][] = new BigInteger[A][B][C];

                for(int i = 0; i<A; i++) {
                    for(int j = 0; j<B; j++) {
                        for(int k = 0; k<C; k++) {
                            BigInteger val;
                            val = sc.nextBigInteger();
                            arr[i][j][k] = val.add(
                                    (j > 0 ? arr[i][j-1][k] : BigInteger.ZERO)).add(
                                     (k > 0 ? arr[i][j][k-1] : BigInteger.ZERO)).add(
                                     (i > 0 ? arr[i-1][j][k] : BigInteger.ZERO)).subtract(
                                     ((k > 0 && j > 0) ? arr[i][j-1][k-1] : BigInteger.ZERO)).subtract(
                                     ((i > 0 && k > 0) ? arr[i-1][j][k-1] : BigInteger.ZERO)).subtract(
                                     ((i > 0 && j > 0) ? arr[i-1][j-1][k] : BigInteger.ZERO)).add(
                                     ((i > 0 && j > 0 && k > 0) ? arr[i-1][j-1][k-1] : BigInteger.ZERO));

                        }
                    }
                }

                BigInteger max_sum = arr[0][0][0];
                // O(n^6)... but the max of n is 20 ~=~ 2^4, thus 2^24? 2^10 = 1024, so 1024^2? Ouch.
                for(int start_i = 0; start_i<A; start_i++) {
                    for(int start_j = 0; start_j<B; start_j++) {
                        for(int start_k = 0; start_k < C; start_k++) {


                            for(int end_i = start_i; end_i<A; end_i++) {
                                for(int end_j = start_j; end_j<B; end_j++) {
                                    for(int end_k = start_k; end_k < C; end_k++) {
                                        BigInteger sum = arr[end_i][end_j][end_k].subtract(
                                                 (start_i > 0 ? arr[start_i-1][end_j][end_k]: BigInteger.ZERO)).subtract(
                                                 (start_j > 0 ? arr[end_i][start_j-1][end_k] : BigInteger.ZERO)).subtract(
                                                 (start_k > 0 ? arr[end_i][end_j][start_k-1] : BigInteger.ZERO)).subtract(
                                                 (start_i > 0 && start_j > 0  && start_k > 0 ? arr[start_i-1][start_j-1][start_k-1] : BigInteger.ZERO)).add(
                                                 (start_i > 0 && start_j > 0 ? arr[start_i-1][start_j-1][end_k] : BigInteger.ZERO)).add(
                                                 (start_i > 0 && start_k > 0 ? arr[start_i-1][end_j][start_k-1] : BigInteger.ZERO)).add(
                                                 (start_j > 0 && start_k > 0 ? arr[end_i][start_j-1][start_k-1] : BigInteger.ZERO));
                                        if(sum.compareTo(max_sum) == 1) max_sum = sum;

                                    }
                                }
                            }


                        }
                    }
                }

                System.out.println(max_sum);
                System.out.println();



            }




    }

}
