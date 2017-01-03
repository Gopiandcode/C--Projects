#include <cstdio>

int main()
{
    int inp[4];
    int i = 0;
    while(scanf("%d %d %d %d", &inp[0], &inp[1], &inp[2], &inp[3]), inp[0] + inp[1] + inp[2] + inp[3] != 0){
        int output = 1080;
        output += ((inp[0]-inp[1] > 0) ? (inp[0] - inp[1]) : (40-inp[1] + inp[0]))*9;
        output += ((inp[2]-inp[1] > 0) ? (inp[2] - inp[1]) : (40-inp[1] + inp[2]))*9;
        output += ((inp[2]-inp[3] > 0) ? (inp[2] - inp[3]) : (40-inp[3] + inp[2]))*9;
        printf("%d\n", output);
    }

    return 0;
}

