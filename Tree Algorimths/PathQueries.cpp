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
vector<int> a[maxN];
int p[maxN], n, L[maxN], R[maxN], K;
long long IT[maxN * 4], lazy[maxN * 4], cost[maxN];

void down(int k, int l, int r){
    long long t = lazy[k];
    if (t == 0 || l > r) return;
    IT[k] += t;
    lazy[k] = 0;
    if (l == r) return;
    lazy[k * 2] += t;
    lazy[k * 2 + 1] += t;
}

void update(int k, int l, int r, int u, int v, long long val){

    down(k, l, r);
    if(v < l || u > r) return;
    //cerr << k << ' ' << u << ' ' << r << '\n';
    if (u <= l && r <= v) {
        lazy[k] += val;
        down(k, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(k * 2, l, mid, u, v, val);
    update(k * 2 + 1, mid + 1, r, u, v, val);
    IT[k] = IT[k * 2] + IT[k * 2 + 1];
}

long long get(int k, int l, int r, int u, int v){
    down(k, l, r);
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) return IT[k];
    int mid = (l + r) / 2;
    long long L = get(k * 2, l, mid, u, v);
    long long R = get(k * 2 + 1, mid + 1, r, u, v);
    return L + R;
}

void DFS(int u, int pa){
    L[u] = ++K;
    for(int v : a[u]){
        if (v == pa) continue;
        cost[v] = cost[u] + p[v];
        DFS(v, u);
    }
    R[u] = K;
}

void solve(){
    int m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    for(int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    cost[1] = p[1];
    DFS(1, -1);
    for(int i = 1; i <= n; i++)
        update(1, 1, K, L[i], L[i], cost[i]);
    while(m--){
        int k;
        cin >> k;
        if (k == 1){
            int x, val;
            cin >> x >> val;
            update(1, 1, K, L[x], R[x], val - p[x]);
            p[x] = val;
        }
        else {
            int x;
            cin >> x;
            cout << get(1, 1, K, L[x], L[x]) << '\n';
        }
    }
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}
