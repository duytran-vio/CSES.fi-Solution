#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<int, ii> i2;

const int maxN = 2e3 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;

struct DinicFlow{
    int n;
    int NumEdge = 0;
    vector<int> points, flow, cap, next, head, work, dist;
    DinicFlow(int _n){
        n = _n;
        NumEdge = 0;
        head.assign(n + 7, -1);
        dist.assign(n + 7, -1);
        work.assign(n + 7, -1);
    }

    void addEdge(int u, int v, int c1, int c2){
        // u -> v
        points.push_back(v);
        flow.push_back(0);
        cap.push_back(c1);
        next.push_back(head[u]);
        head[u] = NumEdge++;
        // v -> u
        points.push_back(u);
        flow.push_back(0);
        cap.push_back(c2);
        next.push_back(head[v]);
        head[v] = NumEdge++;
    }

    bool BFS(int s, int t){
        for(int i = 1; i <= n; i++) dist[i] = -1;
        queue<int> que;
        que.push(s);
        dist[s] = 0;
        while (!que.empty()){
            int u = que.front();
            que.pop();
            for(int i = head[u]; i != -1; i = next[i]){
                int v = points[i];
                int f = flow[i];
                int c = cap[i];
                if (dist[v] == -1 && f < c){
                    dist[v] = dist[u] + 1;
                    if (v == t) return true;
                    que.push(v);
                }
            }
        }
        return false;
    }

    int DFS(int s, int t, int f){
        if (s == t) return f;
        for(int &i = work[s]; i != -1; i = next[i]){
            int v = points[i];
            if (dist[v] == dist[s] + 1 && flow[i] < cap[i]){
                int delta = DFS(v, t, min(f, cap[i] - flow[i]));
                if (delta != INF){
                    flow[i] += delta;
                    flow[i ^ 1] -= delta;
                    return delta;
                }
            }
        }
        return INF;
    }

    long long maxFlow(int s, int t){
        long long res = 0;
        while(BFS(s, t)){
            for(int i = 1; i <= n; i++) work[i] = head[i];
            while(true){
                int delta = DFS(s, t, INF);
                if (delta == INF) break;
                res += delta;
            }
        }
        return res;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    DinicFlow df(n);
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        df.addEdge(x, y, w, 0);
    }
    cout << df.maxFlow(1, n);
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}

