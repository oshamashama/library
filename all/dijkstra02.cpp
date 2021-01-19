struct edge{
    int to, cost;
};
struct DIJKSTRA {
    edge e;
    std::vector<std::vector<edge> > cost;
    std::vector<int> d;
    int v;
    int N;
    void init(int n) {
        std::vector<std::vector<edge> > cost_(n);
        std::vector<int> d_(n, 1e9 + 7);
        cost = cost_;
        d = d_;
        N = n;
    }
    void reset() {
        std::vector<int> d_(N, 1e9 + 7);
        d = d_;
    }

    void dijkstra(int s) {
        d.at(s) = 0;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
        pq.push(std::make_pair(0, s));
        while(pq.size()) {
            std::pair<int, int> p = pq.top();
            pq.pop();
            int v = p.second;
            if(d.at(v) < p.first) continue;
            for(int i = 0; i < cost.at(v).size(); i++) {
                if(d.at(cost.at(v).at(i).to) > d.at(v) + cost.at(v).at(i).cost) {
                    d.at(cost.at(v).at(i).to) = d.at(v) + cost.at(v).at(i).cost;
                    pq.push(std::make_pair(d.at(cost.at(v).at(i).to), cost.at(v).at(i).to));
                }
            }
            
        }
    }
};