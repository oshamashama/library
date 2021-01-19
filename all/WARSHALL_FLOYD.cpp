struct WARSHALL_FLOYD {
    std::vector<std::vector<long long> > d;
    long long V;
    void init(long long v) {
        std::vector<std::vector<long long> > D(v, vector<long long>(v, 1e18));
        d = D;
        V = v;
    }

    void warshall_floyd() {
        for(long long k = 0; k < V; k++) {
            for(long long i = 0; i < V; i++) {
                for(long long j = 0; j < V; j++) {
                    d.at(i).at(j) = min(d.at(i).at(j), d.at(i).at(k) + d.at(k).at(j));
                }
            }
        }
    }

};