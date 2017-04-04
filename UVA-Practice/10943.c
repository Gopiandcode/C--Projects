#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N = -1, K = -1;

    while(1) {
        scanf("%d %d", &N, &K);
        
        // Identify terminating condition.
        if(N == K && K == 0) break;
        
        // Initialize table for dynamic programming
        long table[K][N+1];
        
        int temp, temp2;
        for(temp = 0; temp < K; temp++){
            for(temp2 = 0; temp2 < N+1; temp2++){
                table[temp][temp2] = 0;
            }
        }

        // Set base case values
        int i, j;
        for(i=0; i<K; i++){
            // The table entry at i,j contains the number of ways of adding i+1
            // values to get j. Thus for a sum of 0, there is always only one way.
            table[i][0] = 1;
        }
        for(i = 0; i<N+1; i++) {
            // Simmilarly, there's only one way to sum 1 element to make n;
            table[0][i] = 1;
        }


        for(i = 1; i<K; i++) {
            int sum = 0;
            for(j = 0; j<N+1; j++){
                sum += table[i-1][j];
                sum %= 1000000;
                table[i][j] = sum;
            }
        }
        int final  = table[K-1][N];
        printf("%d\n",final);
        
    
    }



}
