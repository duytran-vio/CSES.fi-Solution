#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
typedef pair<long long, int> i2;

const int maxN = 1e5 + 5;
const long long INF_LL = 1e15;
vector<ii> a[maxN];
int n, m, cha[maxN];
bool reach, Used[maxN], check[maxN];

void DFS(int u, int temp){
    Used[u] = true;
    for(int i = 0; i < a[u].size(); i++){
        int v = a[u][i].X;
        if (v == n && temp == 1) reach = true;
        if (!Used[v])
            DFS(v, temp | check[v]);
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        a[x].push_back(ii(y, w));
    }

    vector<long long> d(n + 1, -INF_LL);
    d[1] = 0;
    for(int i = 1; i <= n; i++){
        for(int u = 1; u <= n; u++)
        for(int k = 0; k < a[u].size(); k++){
            int v = a[u][k].X;
            int w = a[u][k].Y;
            if (d[v] < d[u] + w){
                d[v] = d[u] + w;
                cha[v] = u;
                if (i == n){
                    check[v] = true;
                    int t = u;
                    while (t != v && !check[t]){
                        check[t] = true;
                        t = cha[t];
                    }
                }
            }
        }
//        for(int u = 1; u <= n; u++)
//            cout << d[u] << ' ';
//        cout << '\n';
    }
//    for(int i = 1; i <= n; i++)
//        cout << d[i] << ' ';
    DFS(1, check[1]);
    if (!reach)cout << d[n];
    else
        cout << -1;
}

int main(){
//    freopen("OB.inp", "r", stdin);
//    freopen("OB.out", "w", stdout);
    solve();
}
