#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>
#include <stack>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

std::vector<int> weight(0);
std::vector<int> value(0);

int val(int **A, int i, int W) {
    if(A[i][W] != -1) return A[i][W];

    if(i == 0) {
        if(weight[i] < W)
            A[i][W] = weight[i];
        else
            A[i][W] = 0;
        return A[i][W];

    }

    if(weight[i] > W) {
        return val(A, i-1, W);
    }
    else {
        int with = val(A, i-1, W-weight[i]) + weight[i];
        int without = val(A, i-1, W);
        A[i][W] = max(with, without);
        return A[i][W];
    }

}


int n;
int m;
int bottomUp(int** A) {
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<=m; j++){
            if(i == 0) {
                if(weight[i] <= j) A[i][j] = value[i];
                else A[i][j] = 0;
            } else {
                if(weight[i] <= j) {
                    int with = A[i-1][j-weight[i]] + value[i];
                    int without = A[i-1][j];
                    A[i][j] = max(with, without);
                } else {
                    A[i][j] = A[i-1][j];
                }
            }
        }
    }
    return A[n-1][m];
}

int d,v;
int t;
int w;
int treasure_count;

int f(int d) {
    return 3*w*d;
}

int finv(int d) {
    return d/(w*3);
}

int main() {
    int i  = 0;
    while(1) {
        if(!i)i++;
        else std::cout << std::endl;
        std::cin >> t >> w;

        std::cin >> treasure_count;

        //std::vector<int> weight(0);
        //std::vector<int> value(0);

        for(int i = 0; i<treasure_count; i++) {

            std::cin >> d >> v;

            value.push_back(v);
            weight.push_back(f(d));
            //items.push_back(3*w*d);
        }

        int **A;
        A = (int **) malloc(sizeof(int *) * treasure_count);
        for(int i = 0; i<treasure_count; i++) {
            A[i] = (int *) malloc(sizeof(int) * t);
            for(int j = 0; j<(t+1); j++) {
                A[i][j] = -1;
            }
        }
        n = treasure_count;
        m = t;


        int result = bottomUp(A);

        std::cout << result << std::endl;

        int pos=  t-1;
        // Now all we gotta do is recreate the result.
        std::stack<int> subs;
        for(int i = treasure_count-1; i >= 0; i--) {
            // If no change, do no wrong, see no thing.
            if(i > 0 && A[i][pos] == A[i-1][pos]) continue;
            if(A[i][pos] > 0)
                subs.push(i), pos -= weight[i];
            //subs.push_back()

        }
        std::cout << subs.size() << std::endl;
        while(!subs.empty()) {
            int ind = subs.top();
            subs.pop();
            std::cout << finv(weight[ind]) << " " << value[ind] << std::endl;
        }
    }

}

