vector<T> ks01(vector<T> &v, vector<T> &w, T &W) {
    T N = v.size();
    vector<T> dp(W + 1, 0);
    for(T i = 0; i < N; i++) {
        for(T j = W - w.at(i); j >= 0; j--) {
            if(dp.at(j)) dp.at(j + w.at(i)) = max(dp.at(j + w.at(i)), dp.at(j) + v.at(i));
        }
        if(w.at(i) < W + 1) dp.at(w.at(i)) = max(dp.at(w.at(i)), v.at(i));
    }
    return dp;
}