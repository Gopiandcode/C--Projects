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
                int s_i = 0, s_j = 0, s_k = 0, e_i = 0, e_j = 0, e_k = 0;
                BigInteger RSum = BigInteger.ZERO;
                BigInteger maxVal = BigInteger.ZERO;
                for(int i = 0; i<A; i++) {
                    for(int j = 0; j<B; j++) {
                        for(int k = 0; k<C; k++) {
                            BigInteger val;
                            val = sc.nextBigInteger();


                            if(i == 0 && j == 0 && k == 0) {
                                RSum = val;
                                maxVal = val;
                            }
                            if(maxVal.compareTo(val) == -1) {
                                maxVal = val;
                            }

                            arr[i][j][k] = val.add(
                                    (j > 0 ? arr[i][j-1][k] : BigInteger.ZERO)).add(
                                     (k > 0 ? arr[i][j][k-1] : BigInteger.ZERO)).add(
                                     (i > 0 ? arr[i-1][j][k] : BigInteger.ZERO)).subtract(
                                     ((k > 0 && j > 0) ? arr[i][j-1][k-1] : BigInteger.ZERO)).subtract(
                                     ((i > 0 && k > 0) ? arr[i-1][j][k-1] : BigInteger.ZERO)).subtract(
                                     ((i > 0 && j > 0) ? arr[i-1][j-1][k] : BigInteger.ZERO)).add(
                                     ((i > 0 && j > 0 && k > 0) ? arr[i-1][j-1][k-1] : BigInteger.ZERO));

                            // As we run through the array, if the sum from start to pos is negative, reset start coords
                                BigInteger sum = BigInteger.ZERO;

                        }
                    }
                }

                BigInteger prevSum = RSum;
                for(int i = 0; i<A; i++) {
                    for(int j = 0; j<B; j++) {
                        for(int k = 0; k<C; k++) {
                            System.out.printf("%d %d %d - %d %d %d\n", s_i, s_j, s_k, e_i, e_j, e_k);

                            // As we run through the array, if the sum from start to pos is negative, reset start coords
                            BigInteger sum = BigInteger.ZERO;

                            sum =arr[i][j][k].subtract(
                                    (s_i > 0 ? arr[s_i-1][j][k]: BigInteger.ZERO)).subtract(
                                    (s_j > 0 ? arr[i][s_j-1][k] : BigInteger.ZERO)).subtract(
                                    (s_k > 0 ? arr[i][j][s_k-1] : BigInteger.ZERO)).subtract(
                                    (s_i > 0 && s_j > 0  && s_k > 0 ? arr[s_i-1][s_j-1][s_k-1] : BigInteger.ZERO)).add(
                                    (s_i > 0 && s_j > 0 ? arr[s_i-1][s_j-1][k] : BigInteger.ZERO)).add(
                                    (s_i > 0 && s_k > 0 ? arr[s_i-1][j][s_k-1] : BigInteger.ZERO)).add(
                                    (s_j > 0 && s_k > 0 ? arr[i][s_j-1][s_k-1] : BigInteger.ZERO));
                            System.out.println(sum + ": max_sum: " + RSum);
                            if(sum.compareTo(prevSum) == - 1) {
                                prevSum = sum;
                                s_i = i;
                                s_j = j;
                                s_k = k;
                            }
                            if(sum.compareTo(RSum) == 1) {
                                RSum = sum;
                                e_i = i;
                                e_j = j;
                                e_k = k;
                            }

                        }
                    }
                }






                BigInteger temp = BigInteger.ZERO;

                temp =arr[e_i][e_j][e_k].subtract(
                        (s_i > 0 ? arr[s_i-1][e_j][e_k]: BigInteger.ZERO)).subtract(
                        (s_j > 0 ? arr[e_i][s_j-1][e_k] : BigInteger.ZERO)).subtract(
                        (s_k > 0 ? arr[e_i][e_j][s_k-1] : BigInteger.ZERO)).subtract(
                        (s_i > 0 && s_j > 0  && s_k > 0 ? arr[s_i-1][s_j-1][s_k-1] : BigInteger.ZERO)).add(
                        (s_i > 0 && s_j > 0 ? arr[s_i-1][s_j-1][e_k] : BigInteger.ZERO)).add(
                        (s_i > 0 && s_k > 0 ? arr[s_i-1][e_j][s_k-1] : BigInteger.ZERO)).add(
                        (s_j > 0 && s_k > 0 ? arr[e_i][s_j-1][s_k-1] : BigInteger.ZERO));

                System.out.println("Temporary Result: " + (temp.compareTo(maxVal) == -1 ? maxVal : temp));

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
