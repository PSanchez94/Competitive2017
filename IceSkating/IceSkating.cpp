// Submission Link: https://codeforces.com/contest/217/submission/27439242

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

using namespace std;
std::vector<bool> Marked;

class Graph
{
    vector< vector<int> > Edge;
    vector<unsigned char> visited;
    
public:
    
    Graph(int V)
    {
        Edge.resize(V);
        visited.resize(V);
    }
    
    void add_edge(int v,int w)
    {
        Edge[v].push_back(w);
    }
    
    void BFS(int s)
    {
        for(auto i : visited) {i = false;}
        list<int> q;
        visited[s] = true;
        q.push_back(s);
        while (!q.empty())
        {
            s = q.front();
            q.pop_front();
            for(auto i : Edge[s])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    Marked[i] = true;
                    q.push_back(i);
                }
            }
        }
        
    }
    
};

int main() {
    std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    
    int N=0,A=0,B=0;
    std::vector<std::pair<int,int>> Inputs;
    
    std::cin >> N;
    Graph SnowDrifts(N);
    for(int i = 0; i < N; ++i) {
        std::cin >> A >> B;
        Inputs.push_back(std::make_pair(A,B));
        Marked.push_back(false);
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0;j<N; ++j) {
            if (((Inputs[i].first == Inputs[j].first) || (Inputs[i].second == Inputs[j].second)) && (i!=j)) {
                SnowDrifts.add_edge(i,j); SnowDrifts.add_edge(j,i);
            }
        }
    }
    
    int Ans=0;
    for (int i=0;i<N;++i) {
        if (!Marked[i]) {
            SnowDrifts.BFS(i);
            Ans++;
        }
    }
    std::cout << (Ans-1) << std::endl;
}