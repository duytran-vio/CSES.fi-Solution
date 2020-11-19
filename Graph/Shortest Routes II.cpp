#include <bits/stdc++.h>
using namespace std;

void open_file(){
    #ifdef INOUT
        freopen("OB.inp", "r", stdin);
        freopen("OB.out", "w", stdout);
    #endif
}

typedef pair<int, int> ii;
typedef pair<long long, int> i2;
#define X first
#define Y second 
const int maxN = 5e3 + 5;
const long long INF = 1e15;
vector<ii> a[maxN];
long long d[maxN][maxN];

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        if (i == j) d[i][j] = 0;
        else d[i][j] = INF;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(ii(y, w));
        a[y].push_back(ii(x, w));
        d[x][y] = d[y][x] = min(d[x][y], (long long)w);
    }

    for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for(int i = 0; i < q; i++){
        int x, y;
        cin >> x >> y;
        if (d[x][y] == INF) cout << -1 << '\n';
        else
            cout << d[x][y] << '\n';
    }
}

int main(int argv, char** argc){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    open_file();
    solve();
}