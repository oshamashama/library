struct BIPARTITE_GRAPH {
    vl color;
    vector<vector<int> > G;
    void init(int v) {
        color.resize(v, 0);
        vector<vector<int> > g(v);
        G = g;
    }
    bool dfs(int v, int c) {
        color.at(v) = c;
        for(int i = 0; i < G.at(v).size(); i++) {
            if(color.at(G.at(v).at(i)) == c) return 0;
            if(color.at(G.at(v).at(i)) == 0 && !dfs(G.at(v).at(i), -c)) return 0;
        }
        return 1;
    }
};