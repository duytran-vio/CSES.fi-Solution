#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<int, ii> i2;

const int maxN = 2e5 + 5;
const long long INF_LL = 1e15;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 100;

int p[maxN][20], depth[maxN], cnt[maxN];
vector<int> a[maxN];

void DFS(int u){
    for(int i = 0; i < 19; i++){
        int v = p[u][i];
        if (v == 0) break;
        p[u][i + 1] = p[v][i];
    }
    for(int v : a[u]){
        if (v == p[u][0]) continue;
        p[v][0] = u;
        depth[v] = depth[u] + 1;
        DFS(v);
    }
}

int LCA(int u, int v){
    if (depth[v] > depth[u]) swap(u, v);
    int delta = depth[u] - depth[v];
    for(int i = 19; i >= 0; i--){
        if ((delta >> i) & 1)
            u = p[u][i];
    }
    if (u == v) return u;
    for(int i = 19; i >= 0; i--){
        if (p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

void countingPath(int u){
    for(int v : a[u]){
        if (v == p[u][0]) continue;
        countingPath(v);
        cnt[u] += cnt[v];
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n - 1; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    DFS(1);
    while(m--){
        int u, v;
        cin >> u >> v;
        int k = LCA(u, v);
        cnt[u]++;
        cnt[v]++;
        cnt[k]--;
        cnt[p[k][0]]--;
    }
    countingPath(1);
    for(int i = 1; i <= n; i++)
        cout << cnt[i] << ' ';
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}
