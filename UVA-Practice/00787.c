#include <stdio.h>
#include <stdlib.h>


int main() {
    
    while(1) {
        long long int sequence[100];
        int i = 0;
        

        // Gets the input.
        while(1){
            long seq;
            scanf("%ld",&seq);
            if(seq == -999999) break;
            sequence[i++] = seq;
        }
        
        
        // Input retrieval loops
        long long int max_complete = 0;
        long long int minimal[i];
        long long int maximal[i];
        int j;
        minimal[0] = maximal[0] = sequence[0];
        for(j = 1; j<i; j++){
            int min;
            int max;
            

            // Algorithm works by maintaininng two contiguous product sums,
            // the greatest one, and the least one - depending on the sequence
            // value, either the minimal or maximal sum is used
            if(sequence[j] < 0) {
                min = maximal[j-1] * sequence[j];
                max = minimal[j-1] * sequence[j];
            } else {
                min = minimal[j-1] * sequence[j];
                max = maximal[j-1] * sequence[j];
            }


            // Update the largest seen.
            if(max > max_complete) max_complete = max;
            if(min > max_complete) max_complete = min;
            if(sequence[j] > max_complete) max_complete = sequence[j];
            

	    // Note to self: minimal and maximal only use the last seen value,
            // so there's no need for an array. Possibly this could improve space
            // requirements for the algorithm.
            minimal[j] = (sequence[j] < min) ? sequence[j] : min;
            maximal[j] = (sequence[j] > max) ? sequence[j] : max;

        }

        printf("%ld\n", max_complete);

    }



}
