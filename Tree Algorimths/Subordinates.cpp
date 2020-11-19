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

int f[maxN];
vector<int> a[maxN];

void DFS(int u, int pa){
    for(int v : a[u]){
        if (v == pa) continue;
        DFS(v, u);
        f[u] += f[v];
    }
    f[u]++;
}

void solve(){
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    DFS(1, -1);
    for(int i = 1; i <= n; i++)
        cout << f[i] - 1 << ' ';
}

int main(){
    freopen("OB.inp", "r", stdin);
    freopen("OB.out", "w", stdout);
    solve();
}

