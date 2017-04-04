#include <stdio.h>
#include <stdlib.h>


int main() {

    while(1) {
        int l;
        int n;
        int i,j,k,x;

        // Get input and check end condition.
        scanf("%d", &l);
        if(0 == l) break;
        
        // Get the number of cuts.
        scanf("%d",&n);

        int c[n+2];
        
        // Retrieve each cut.
        for(i = 1; i<n+1;i++) {
            scanf("%d", &c[i]);
        }
        // We are using the array to represent all the endpoints, thus include 0 and max.
        c[0] = 0;
        c[n+1] = l;
        
        // Initialize array for dynamic programming.
        long dyn_prog[n+2][n+2];
        for(i = 0; i<n+2; i++){
            for(j =0;j<n+2; j++){
                dyn_prog[i][j] = -1;
            }
        }
        for(i = 0; i<n+1; i++){
            dyn_prog[i][i+1] = 0;
        }
        // Retrieve values for dynamic programming
        for(k = 1; k<n+2; k++){
            for(i = 0; i<n+2; i++){
                for(j=i+k; j<n+2; j++){
                   // if the difference between i and j is 1, no cost (no cuts needed)
                   if(j-i == 1){
                    dyn_prog[i][j] = 0;
                    
                   }
                   else {
                        // smaller cuts possible, need to check all sub cuts from i to j
                        int min = -1;
                        for(x=0; x < j-i && i+x <n+2; x++){
                            if(dyn_prog[i][i+x] != -1 && dyn_prog[i+x][j] != -1){
                                if(min == -1 || dyn_prog[i][i+x] + dyn_prog[i+x][j] < min){
                                    min = dyn_prog[i][i+x] + dyn_prog[i+x][j];
                                }
                            }
                        }
                        if(min == -1) min = 0;
                        dyn_prog[i][j] = min + c[j] - c[i];
                   }
                }
            }
        }
    printf("The minimum cutting is %ld.\n", dyn_prog[0][n+1]);
    }


}
