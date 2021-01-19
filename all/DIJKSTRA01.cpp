struct DIJKSTRA {
    std::vector<std::vector<int> > cost;
    std::vector<int> d;
    std::vector<bool> used;
    int v;
    int N;
    void init(int n) {
        std::vector<std::vector<int> > cost_(n, std::vector<int>(n, 1e9 + 7));
        std::vector<int> d_(n, 1e9 + 7);
        std::vector<bool> used_(n, 0);
        cost = cost_;
        d = d_;
        used = used_;
        N = n;
    }
    void reset() {
        std::vector<int> d_(N, 1e9 + 7);
        std::vector<bool> used_(N, 0);
        d = d_;
        used = used_;
    }

    void dijkstra(int s) {
        d.at(s) = 0;
        while(true) {
            int v = -1;
            for(int i = 0; i < N; i++) {
                if(!used.at(i) && (v == -1 || d.at(i) < d.at(v))) {
                    v = i;
                }
            }
            if(v == -1) return;
            used.at(v) = 1;
            for(int i = 0; i < N; i++) {
                d.at(i) = std::min(d.at(i), d.at(v) + cost.at(v).at(i));
            }
        }
    }
};
