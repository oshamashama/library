struct UF {
    std::vector<int> parents;
    std::vector<int> rank;

    void init(int n) {
        std::vector<int> R(n);
        parents = rank = R;
        for(int i = 0; i < n; i++) {
            parents.at(i) = i;
            rank.at(i) = 0;
        }
    }

    int find(int x) {
        if(parents.at(x) == x) {
            return x;
        } else {
            return parents.at(x) = find(parents.at(x));
        }
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        if(rank.at(x) > rank.at(y)) {
            parents.at(y) = x;
        } else if(rank.at(x) < rank.at(y)) {
            parents.at(x) = y;
        } else {
            parents.at(x) = y;
            rank.at(x)++;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

};