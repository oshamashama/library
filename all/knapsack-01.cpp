#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> ks01(vector<ll> &v, vector<ll> &w, ll &W) {
    ll N = v.size();
    vector<ll> dp(W + 1, 0);
    for(ll i = 0; i < N; i++) {
        for(ll j = W; j >= 0; j--) {
            if(dp.at(j) && j + w.at(i) < W + 1) {
                dp.at(j + w.at(i)) = max(dp.at(j + w.at(i)), dp.at(j) + v.at(i));
            }
        }
        if(w.at(i) < W + 1) {
            dp.at(w.at(i)) = max(dp.at(w.at(i)), v.at(i));
        }
    }
    return dp;
}