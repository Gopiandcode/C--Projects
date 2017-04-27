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

std::vector<int> value;
std::vector<int> weight;

int **A;

int val(int i, int W) {
    if(A[i][W] != -1) return A[i][W];
    if(i == 0) {
        if(weight[i] <= W) A[i][W] = value[i];
        else A[i][W] = 0;
        return A[i][W];
    }


    if(weight[i] > W) {
        // Is just too big, move on buddies
        return val(i-1, W);
    } else {
        int with = val(i-1, W-weight[i]) + value[i];
        int without = val(i-1, W);
        A[i][W] = max(with, without);
        return A[i][W];
    }



}

int main() {
    int T;
    std::cin >> T;
    for(int test_case = 0; test_case < T; test_case++) {
        int N;
        std::cin >> N;
        value.clear();
        weight.clear();

        for(int i = 0; i<N; i++) {
            int P;
            int W;
            std::cin >> P >> W;
            value.push_back(P);
            weight.push_back(W);
        }
        int G;
        std::vector<int> fam;

        std::cin >> G;



        int inp;
        int mix = -1;
        for(int i  =0; i<G; i++) std::cin >> inp, fam.push_back(inp), (mix == -1 || inp > mix ? mix = inp : 0);

        A = (int **) malloc(sizeof(int *) * N);
        for(int i = 0; i<N ;i ++) {
            A[i] = (int *) malloc(sizeof(int) * (mix + 1));
            for(int j = 0; j<=mix; j++) A[i][j] = -1;

        }


        int total = 0;
        for(int i : fam) {
            int zix = val(N-1, i);
            total += zix;
        }

        std::cout << total << std::endl;


    }
}

