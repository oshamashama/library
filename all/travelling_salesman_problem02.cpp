#include <bits/stdc++.h>

struct TSP {
    int N;
    std::vector<std::vector<int> > d, dp;
    
    void init(int n) {
        std::vector<std::vector<int> > d_(n, std::vector<int>(n,1e9)), dp_(1 << n, std::vector<int>(n,-1));
        d = d_;
        dp = dp_;
        N = n;
    }
    int rec(int S, int v) {
        if(dp.at(S).at(v) >= 0) {
            return dp.at(S).at(v);
        }
        if(S == (1 << N) - 1 && v == 0) {
            return dp.at(S).at(v) = 0;
        }
        int res = 1e9;
        for(int i = 0; i < N; i++) {
            if(!(S >> i & 1)) {
                res = std::min(res, rec(S | 1 << i, i) + d.at(v).at(i));
            }
        }
        return dp.at(S).at(v) = res;
    }

};