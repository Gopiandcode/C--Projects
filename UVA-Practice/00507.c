#include <stdio.h>
#include <stdlib.h>

int main() {
    


    int b;
    scanf("%d", &b);

    int i, j;

    int *routes[b];

    // Simple getting inputs loop.
    for(i = 0; i<b; i++) {
        int r;
        scanf("%d", &r);
        routes[i] = (int *)malloc(sizeof(int)*(r));
        routes[i][0] = r;
        
        for(j = 1; j<r; j++){
            scanf("%d", &routes[i][j]);
        }
        
    }

    // Solving the problem loop.
    for(i = 0; i<b; i++){
        
        int best_i = -1;
        int best_j = -1;
        int max_sum = 0;
        int curr_i = 0, curr_j = 0;
        int sum = 0;
	int count = 0;
	int max_count = 0;

        // Loop through the values, doing a cumulative sum
        // whenever the sum drops below 0, clear the sum.
        // Also to conform to requirements of question, keep track of the length.
        for(j=1; j<routes[i][0]; j++){
            count++;
	    sum += routes[i][j];
            curr_j = j;

            // If the sum is 0, update the current_i
            // and clear the sum and the length
            if(sum < 0) {
                curr_i = j;
                sum = 0;
		count = 0;
            }


            // If the sum is greater than the maximum we
            // we have recorded, update the sum. If the count is greater,
            // prefer the new value - as per question requrements.
            if((sum != 0 && sum > max_sum) || (count > max_count && sum >=max_sum)){
                if(count > max_count) max_count = count;
		max_sum = sum;
                
                best_i = curr_i;
                best_j = curr_j;
            }
        }

	// Finally once complete, print the final statements.
        if(best_i != -1 && best_j != -1 && max_sum != 0){
            printf("The nicest part of route %d is between stops %d and %d\n", i+1, best_i+1, best_j+1);
        } else {
            printf("Route %d has no nice parts\n", i+1);
        }

    }



}
