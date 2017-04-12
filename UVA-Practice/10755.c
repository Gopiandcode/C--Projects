#include <iostream>
#include <cstdio>


int main() {
    // Basic initialization
    int test_cases;
    scanf("%d", &test_cases);


    while(test_cases--) {

        // Get the dimensions of the array
        int A, B, C;
        scanf("%d%d%d", &A, &B, &C);

        // Need a long long arr to store all the large values
        long long arr[A][B][C];

        // Basic initialization loop - tried doing something with memorization and longest running sum but didn't work.
        for(int i = 0; i<A; i++) {
            for(int j = 0; j<B; j++) {
                for(int k = 0; k<C; k++) {
                    // Get the input.
                    long long val;
                    scanf("%lld", &val);

                    // Calculate the sum from 0,0 to that point
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
        
        // Long long to get the max sum-sum
        long long max_sum = arr[0][0][0];
        
        // I'm sure there's a way to do this better than n^6 with something like memorization, but I haven't found it - see Java code for attempt.
        // O(n^6)... but the max of n is 20 ~=~ 2^4, thus 2^24? 2^10 = 1024, so 1024^2? Ouch.
        for(int start_i = 0; start_i<A; start_i++) {
            for(int start_j = 0; start_j<B; start_j++) {
                for(int start_k = 0; start_k < C; start_k++) {
                        for(int end_i = start_i; end_i<A; end_i++) {
                            for(int end_j = start_j; end_j<B; end_j++) {
                                for(int end_k = start_k; end_k < C; end_k++) {
                                    // Long long sum to calculate sum-sum from starting to end coords.
                                    long long sum = arr[end_i][end_j][end_k]
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

        printf("%lld\n", max_sum);
        if(test_cases) printf("\n");



    }

}

