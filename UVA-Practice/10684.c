#include <iostream>
#include <cstdio>


int main() {
    while(1) {
        // Get the input
        int N;
        scanf("%d", &N);

        // Check terminating condition
        if(N == 0) break;

        // Simple running sum contiguous sequence.
        int max_sum  = 0;
        int current_sum = 0;
        for(int i = 0; i<N; i++) {

            // Get each input.
            int j;
            scanf("%d", &j);
            current_sum += j;

            // Check if it's worthwhile to keep counting.
            if(current_sum < 0) current_sum = 0;


            // Check whether max sum needs to be updated.
            if(current_sum > max_sum) max_sum = current_sum;
        }


        if(max_sum) printf("The maximum winning streak is %d.\n", max_sum);
        else printf("Losing streak.\n");
    }


}




