#include <iostream>
#include <cstdio>


int main() {
    // Get the size of the array
    int N;
    scanf("%d", &N);

    int arr[N][N];

    // Get the input array - calculate a running sum array.
    for(int i = 0; i<N; i++) {
        for(int j = 0; j<N; j++) {
            int val;
            scanf("%d", &val);
            arr[i][j] = ((i > 0) ? arr[i-1][j] : 0) + ((j > 0) ? arr[i][j-1] : 0) + val - ((i > 0 && j > 0) ? arr[i-1][j-1] : 0);
        }
    }

    int max_sum = 0;

    // Enter the main loop - use the running sum to consider all
    // possible sum-array sums in O(1) - n^4 checks total.
    for(int i_start = 0; i_start<N; i_start++) {
        for(int j_start = 0; j_start<N; j_start++) {

            for(int i_end = i_start; i_end < N; i_end++) {
                for(int j_end = j_start; j_end < N; j_end++) {

                    int big_val= arr[i_end][j_end];
                    int upper_val = (i_start > 0 ? arr[i_start -1][j_end] : 0);
                    int lefter_val = (j_start > 0 ? arr[i_end][j_start-1] : 0);
                    int adder_val = (i_start > 0 && j_start > 0 ? arr[i_start-1][j_start-1] : 0);

                    int val = big_val - upper_val - lefter_val + adder_val;
                    if(val > max_sum) max_sum = val;
                }
            }
        }
    }
    printf("%d\n", max_sum);

}

