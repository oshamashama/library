#include <bits/stdc++.h>

const long long INF = 1e9;
const long long MOD = 1e9 + 7;
//const long long MOD = 998244353;
const long long LINF = 1e18;
using namespace std;

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define POSSIBLE(n) cout << ((n) ? "POSSIBLE" : "IMPOSSIBLE"  ) << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible"  ) << endl
#define dump(x)  cout << #x << " = " << (x) << endl
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPR(i,n) for(int i=n;i>=0;i--)
#define COUT(x) cout<<(x)<<endl
#define SCOUT(x) cout<<(x)<<" "
#define VECCOUT(x) for(auto&youso_: (x) )cout<<youso_<<" ";cout<<endl
#define ENDL cout<<endl
#define CIN(...) int __VA_ARGS__;CINT(__VA_ARGS__)
#define LCIN(...) long long __VA_ARGS__;CINT(__VA_ARGS__)
#define SCIN(...) string __VA_ARGS__;CINT(__VA_ARGS__)
#define VECCIN(x) for(auto&youso_: (x) )cin>>youso_
#define mp make_pair
#define PQ priority_queue<long long>
#define PQG priority_queue<long long,V,greater<long long>>



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
struct DIJKSTRA2 {
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

void Main() {
    TSP tsp;
    int V, E;
    cin >> V >> E;
    tsp.init(V);
    for(int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        tsp.d.at(s).at(t) = d;
    }
    int ans = tsp.rec(0, 0);
    if(ans == 1e9) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

void Main2() {
    DIJKSTRA dj;
    int V, E, r;
    cin >> V >> E >> r;
    dj.init(V);
    for(int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        edge  e;
        e.to = t;
        e.cost = d;
        dj.cost.at(s).push_back(e);
//        dj.cost.at(t).push_back(e);
//        dj.cost.at(s).at(t) = d;
    }
    dj.dijkstra(r);
    for(int i = 0; i < V; i++) {
        if(dj.d.at(i) == (1e9 + 7)) {
            cout << "INF" << endl;
        } else {
            cout << dj.d.at(i) << endl;
        }
    }
}

int main() {
    cout << fixed << setprecision(15);
    Main();
    return 0;
}