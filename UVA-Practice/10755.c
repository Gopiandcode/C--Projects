#include <iostream>
#include <cstdio>


int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for(int i = 0; i<test_cases; i++) {
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);

        long long arr[A][B][C];

        for(int i = 0; i<A; i++) {
            for(int j = 0; j<B; j++) {
                for(int k = 0; k<C; k++) {
                    int val;
                    scanf("%d", &val);

                    arr[i][j][k] = val
                    + (j ? arr[i][j-1][k] : 0)
                    + (k ? arr[i][j][k-1] : 0)
                    + (i ? arr[i-1][j][k] : 0)
                    - ((k && j) ? arr[i][j-1][k-1] : 0)
                    - ((i && k) ? arr[i-1][j][k-1] : 0)
                    - ((i && j) ? arr[i-1][j-1][k] : 0)
                    + ((i && j && k) ? arr[i-1][j-1][k-1] : 0);

                }
            }
        }

        long long max_sum = arr[0][0][0];
        // O(n^6)... but the max of n is 20 ~=~ 2^4, thus 2^24? 2^10 = 1024, so 1024^2? Ouch.
        for(int start_i = 0; start_i<A; start_i++) {
            for(int start_j = 0; start_j<B; start_j++) {
                for(int start_k = 0; start_k < C; start_k++) {


                        for(int end_i = start_i; end_i<A; end_i++) {
                            for(int end_j = start_j; end_j<B; end_j++) {
                                for(int end_k = start_k; end_k < C; end_k++) {
                                    int sum = arr[end_i][end_j][end_k]
                                               - (start_i ? arr[start_i-1][end_j][end_k]: 0)
                                               - (start_j ? arr[end_i][start_j-1][end_k] : 0)
                                               - (start_k ? arr[end_i][end_j][start_k-1] : 0)
                                               - (start_i && start_j && start_k ? arr[start_i-1][start_j-1][start_k-1] : 0)
                                               + (start_i && start_j ? arr[start_i-1][start_j-1][end_k] : 0)
                                               + (start_i && start_k ? arr[start_i-1][end_j][start_k-1] : 0)
                                               + (start_j && start_k ? arr[end_i][start_j-1][start_k-1] : 0);
                                    if(sum > max_sum) max_sum = sum;

                                }
                            }
                        }


                }
            }
        }

        printf("%lld\n\n", max_sum);



    }

}

