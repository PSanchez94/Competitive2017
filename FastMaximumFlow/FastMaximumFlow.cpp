// Submission Link: https://www.spoj.com/status/FASTFLOW,kasisanchez/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

class Dinic {
    struct edge {
        int to, rev;
        long long f, cap;
    };
    
    std::vector<std::vector<edge>> g;
    std::vector<long long> dist;
    std::vector<int> q, work;
    int n, sink;
    
    bool bfs(int start, int finish) {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail) {
            int u = q[head++];
            for (const edge &e : g[u]) {
                int v = e.to;
                if (dist[v] == -1 and e.f < e.cap) {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return dist[finish] != -1;
    }
    
    long long dfs(int u, long long f) {
        if (u == sink)
            return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i) {
            edge &e = g[u][i];
            int v = e.to;
            if (e.cap <= e.f or dist[v] != dist[u] + 1)
                continue;
            long long df = dfs(v, std::min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }
    
public:
    Dinic(int n) {
        this->n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }
    
    void add_edge(int u, int v, long long cap) {
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0, cap}; //Poner cap en vez de 0 si la arista es bidireccional
        g[u].push_back(a);
        g[v].push_back(b);
    }
    
    long long max_flow(int source, int dest) {
        sink = dest;
        long long ans = 0;
        while (bfs(source, dest)) {
            work.assign(n, 0);
            while (long long delta = dfs(source, LLONG_MAX))
                ans += delta;
        }
        return ans;
    }
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    
    int N, M, A, B, C;
    std::cin >> N >> M;
    Dinic graph(N+1);
    
    for (int i=0; i<M; ++i) {
        std::cin >> A >> B >> C;
        graph.add_edge(A, B, C);
    }
    
    std::cout << graph.max_flow(1,N) << std::endl;
    
}