#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
using Pair = pair<int,int>;
#define get(a,b, cols) ((a) + ((b) * cols))

struct pair_hash {
    template<class T1, class T2>
    size_t operator()(const pair<T1,T2> &p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};


class Problem {
public:
    Problem(vector<int>, int, int, int);
    int f(int a, int b);
    int findhigh(int low);
    int findlow(int high);
private:
    unordered_map<Pair,int, pair_hash> f_memoization;
    unordered_map<int,int> findhigh_memoization;
    unordered_map<int,int> findlow_memoization;
    vector<int> points;
    int k;
    int max_dist;
    int min_dist;
};

Problem::Problem(vector<int> p, int k_v, int max_d, int min_d) : points(p), k(k_v), max_dist(max_d), min_dist(min_d) {}

int Problem::f(int a, int b) {
    if(b < a) {
        int temp = b;
        b = a;
        a = temp;
    }
    Pair p(a,b);
    unordered_map<Pair, int, pair_hash>::iterator iter = f_memoization.find(p);
    if(iter != f_memoization.end()) {
        return iter->second;
    }
    else {
        // if within 1, check distances
        if(a == b) {
            f_memoization[p] = 1;
            return 1;
        }
        if(b - a == 1) {
            int res = 0;
            if(points[b] - points[a] < k) res = 1;
            else  res = 2;
            f_memoization[p] = res;
            return res;
        }

        int f_best = -1;
        for(int i = a; i <= b; ++i) {
            int xplk = points[i] + k;
            int xmlk = points[i] - k;
            int hp = (xmlk > min_dist) ? findhigh(xmlk) : -1;
            int lp = (xplk < max_dist) ? findlow(xplk) : -1;
            if(hp > b || hp < a) hp = -1;
            if(lp > b || lp < a) lp = -1;
            // cout << "For a-b("<< a << "-" << b <<")  x = " << i <<", lp: " << lp << ", hp: " << hp << "\n";
            int f_curr = (hp == -1 ? 0 : f(a,hp)) + (lp == -1 ? 0 : f(lp,b)) + 1;
            if(f_best == -1 || f_curr < f_best) f_best = f_curr;
        }

        f_memoization[p] = f_best;
        return f_best;

    }
}

int Problem::findhigh(int low) {
    //cout << "findhigh(" << low << ") = ";
    unordered_map<int,int>::iterator iter = findhigh_memoization.find(low);
    if(iter != findhigh_memoization.end()) {
        //cout << iter->second << "\n";
        return iter->second;
    }
    else {
        // find the highest point below low

        for(int i = points.size()-1;i >= 0; --i){
            if(points[i] < low){
                findhigh_memoization[low] = i;
                // cout << i << "\n";
                return i;
            }
        }
        return -1;

    }
}

int Problem::findlow(int high) {
    unordered_map<int,int>::iterator iter = findlow_memoization.find(high);
    if(iter != findlow_memoization.end()) return iter->second;
    else {
        // find the lowest point above high

        for(int i = 0;i < points.size(); ++i){
            if(points[i] > high){
                findlow_memoization[high] = i;
                return i;
            }
        }
        return -1;
    }
}
int checkprev(int pos, vector<int> &x, vector<int> &hit, int k) {
    int temp = pos - 1;
    while(temp >= 0 && x[pos+1] - k <= x[temp]) {
        temp--;
    }
    while(temp >= 0 && x[pos] - k <= x[temp]) {
        if(!hit[temp]) return 1;
        temp--;
    }
    return 0;

}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    int low,high;
    for(int x_i = 0;x_i < n;x_i++){
        cin >> x[x_i];
        if(x_i == 0){
            low = x[x_i];
            high = x[x_i];
        } else {
            if(x[x_i] < low) low = x[x_i];
            if(x[x_i] > high) high = x[x_i];
        }
    }
    set<int> s;
    unsigned size = x.size();
    for( unsigned i = 0; i < size; ++i ) s.insert( x[i] );
    x.assign( s.begin(), s.end() );

    // While the DP approach worked, it was too slow.
    //Problem p(x, k, high,low);
    //cout << p.f(0, x.size()-1);

    vector<int> hit(x.size());
    for(int i = 0; i < hit.size(); i++) hit[i] = 0;
    int res = 0;
    int last_marked = 0;
    for(int i = 0; i < x.size()-1;++i) {
        // if it hasn't been hit
        if(!hit[i]) {
            // if the next one along is too far to reach or the previous one won't be hit
            if(x[i + 1] - k > x[i] || checkprev(i,x,hit, k)) {
                res++;
                int temp = i-1;
                while(temp >= 0 && x[i] - k <= x[temp]){
                    hit[temp--] = 1;
                }
                temp = i + 1;
                while(temp < hit.size() && x[i] + k >= x[temp]){
                    hit[temp++] = 1;
                }
                hit[i] = 1;
            }
        }
    }
    if(!hit[x.size()-1]) res++;
    // AAAAAAARGH. After I went and found a nice DP solution, a greedy approach ended up being the best.
    cout << res;
    return 0;
}
