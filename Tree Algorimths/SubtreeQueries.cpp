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
long long IT[maxN * 4];

void update(int k, int l, int r, int u, int val){
    if(u < l || u > r) return;
    if (l == r) {
        IT[k] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(k * 2, l, mid, u, val);
    update(k * 2 + 1, mid + 1, r, u, val);
    IT[k] = IT[k * 2] + IT[k * 2 + 1];
}

long long get(int k, int l, int r, int u, int v){
    if (v < l || u > r) return 0;
    if (u <= l && r <= v) {
        return IT[k];
    }
    int mid = (l + r) / 2;
    long long L = get(k * 2, l, mid, u, v);
    long long R = get(k * 2 + 1, mid + 1, r, u, v);
    return L + R;
}

void DFS(int u, int pa){
    L[u] = ++K;
    for(int v : a[u]){
        if (v == pa) continue;
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

    DFS(1, -1);
    for(int i = 1; i <= n; i++)
        update(1, 1, K, L[i], p[i]);
    while(m--){
        int k;
        cin >> k;
        if (k == 1){
            int x, val;
            cin >> x >> val;
            update(1, 1, K, L[x], val);
        }
        else {
            int x;
            cin >> x;
            cout << get(1, 1, K, L[x], R[x]) << '\n';
        }
    }
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}
